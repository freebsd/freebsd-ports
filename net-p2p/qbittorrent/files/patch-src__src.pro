--- ./src/src.pro.orig	2014-02-02 21:50:54.000000000 +0100
+++ ./src/src.pro	2014-02-06 23:30:26.000000000 +0100
@@ -107,8 +107,7 @@
            scannedfoldersmodel.h \
            qinisettings.h \
            smtp.h \
-           dnsupdater.h \
-           messageboxraised.h
+           dnsupdater.h
 
 
 SOURCES += main.cpp \
@@ -117,8 +116,7 @@
            misc.cpp \
            fs_utils.cpp \
            smtp.cpp \
-           dnsupdater.cpp \
-           messageboxraised.cpp
+           dnsupdater.cpp
 
 nox {
   HEADERS += headlessloader.h
@@ -152,7 +150,8 @@
               loglistwidget.h \
               addnewtorrentdialog.h \
               autoexpandabledialog.h \
-              statsdialog.h
+              statsdialog.h \
+                         messageboxraised.h
 
   SOURCES += mainwindow.cpp \
              ico.cpp \
@@ -171,7 +170,8 @@
              loglistwidget.cpp \
              addnewtorrentdialog.cpp \
              autoexpandabledialog.cpp \
-             statsdialog.cpp
+             statsdialog.cpp \
+             messageboxraised.cpp
 
   win32 {
     HEADERS += programupdater.h
