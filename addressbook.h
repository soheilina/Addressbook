/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "finddialog.h"
#include <QWidget>
#include <QMap>

class QLabel;
class QLineEdit;
class QTextEdit;
class QPushButton;

class AddressBook : public QWidget
{
    Q_OBJECT    //?? what kind of Macro?! Link: http://www.programmerinterview.com/index.php/c-cplusplus/inline-vs-macro/
                //"For now, it is useful to think of the Q_OBJECT macro as a shortcut which allows us to use the tr() and connect() functions."

public:
    AddressBook(QWidget *parent = 0);
    enum Mode {NavigationMode, AddingMode, EditingMode }; //

public slots:   //?? what is it?!
    void addContact();
    void submitContact();
    void cancel();
    void next();
    void previous();
    void editContact();
    void removeContact();
    void findContact();

private:
    void updateInterface(Mode mode);
    QLineEdit *nameLine;
    QTextEdit *addressText;
    QPushButton *addButton;
    QPushButton *submitButton;
    QPushButton *cancelButton;
    QPushButton *nextButton;
    QPushButton *previousButton;
    QPushButton *removeButton;
    QPushButton *editButton;
    QPushButton *findButton;
    FindDialog *dialog;

    QMap<QString,QString> contacts; //a container to store our address book contacts, so that we can traverse and display them
    QString oldName;
    QString oldAddress;
    Mode currentMode;
};

#endif
