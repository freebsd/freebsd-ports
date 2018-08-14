--- qtfm.pro.orig	2012-06-04 19:48:11.000000000 +0800
+++ qtfm.pro	2018-07-22 18:29:04.602178000 +0800
@@ -31,7 +31,7 @@
 CONFIG += release warn_off thread
 RESOURCES += resources.qrc
 QT+= network
-LIBS += -lmagic
+LIBS += -lmagic -linotify
 
 TARGET = qtfm
 target.path = /usr/bin
@@ -56,7 +56,7 @@
                translations/qtfm_zh.qm \
                translations/qtfm_zh_TW.qm
 
-INSTALLS += target desktop icon docs trans
+INSTALLS += target desktop icon trans
 
 
 
