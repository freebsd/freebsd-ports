--- twmnd/twmnd.pro.orig	2019-09-17 23:27:49 UTC
+++ twmnd/twmnd.pro
@@ -10,7 +10,8 @@ TARGET = twmnd
 TEMPLATE = app
 CONFIG += debug
 DESTDIR = ../bin/
-QMAKE_CXXFLAGS += -Wall -Werror -pedantic -Wno-long-long
+QMAKE_CXXFLAGS_WARN_ON -= -W
+QMAKE_CXXFLAGS += -Wall -Werror -pedantic -Wno-long-long -Wno-error=deprecated
 
 target.path+=/usr/local/bin
 INSTALLS += target
