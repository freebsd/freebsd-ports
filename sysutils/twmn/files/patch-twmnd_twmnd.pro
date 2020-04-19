--- twmnd/twmnd.pro.orig	2020-04-19 16:05:55 UTC
+++ twmnd/twmnd.pro
@@ -10,7 +10,7 @@ TARGET = twmnd
 TEMPLATE = app
 CONFIG += debug
 DESTDIR = ../bin/
-QMAKE_CXXFLAGS += -Wall -Werror -pedantic -Wno-long-long
+QMAKE_CXXFLAGS += -Wall -pedantic -Wno-long-long
 
 target.path+=/usr/local/bin
 INSTALLS += target
