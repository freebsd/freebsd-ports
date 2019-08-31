--- x2goclient.pro.orig	2019-08-31 16:08:02 UTC
+++ x2goclient.pro
@@ -132,7 +132,7 @@ SOURCES += src/sharewidget.cpp \
            src/compat.cpp \
            src/pulsemanager.cpp
 
-LIBS += -lssh -lssh_threads
+LIBS += -lssh
 win32:LIBS += -lAdvAPI32 -lshell32 -lUser32
 
 RC_FILE = res/x2goclient.rc
