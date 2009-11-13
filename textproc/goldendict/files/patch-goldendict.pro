--- goldendict.pro.orig	2009-05-24 23:28:51.000000000 +0400
+++ goldendict.pro	2009-11-12 18:57:44.000000000 +0300
@@ -35,24 +35,20 @@
     LIBS += -lXtst
     PREFIX = $$(PREFIX)
     isEmpty( PREFIX ):PREFIX = /usr/local
-    DEFINES += PROGRAM_DATA_DIR=\\\"$$PREFIX/share/apps/goldendict/\\\"
+    isEmpty( DESKTOPDIR ):DESKTOPDIR = $$PREFIX/share/applications
+    isEmpty( ICONDIR ):ICONDIR = $$PREFIX/share/pixmaps
+    DEFINES += PROGRAM_DATA_DIR=\\\"$$PREFIX/share/goldendict/\\\"
     target.path = $$PREFIX/bin/
-    locale.path = $$PREFIX/share/apps/goldendict/locale/
+    locale.path = $$PREFIX/share/goldendict
     locale.files = locale/*.qm
     INSTALLS += target \
         locale
-    icons.path = /usr/share/pixmaps
-    icons.files = redist/icons/*.*
+    icons.path = $$ICONDIR
+    icons.files = redist/icons/goldendict.png
     INSTALLS += icons
-    icons2.path = /usr/share/app-install/icons
-    icons2.files = redist/icons/*.*
-    INSTALLS += icons2
-    desktops.path = /usr/share/applications
-    desktops.files = redist/*.desktop
+    desktops.path = $$DESKTOPDIR
+    desktops.files = redist/goldendict.desktop
     INSTALLS += desktops
-    desktops2.path = /usr/share/app-install/desktop
-    desktops2.files = redist/*.desktop
-    INSTALLS += desktops2
 }
 DEFINES += PROGRAM_VERSION=\\\"$$VERSION\\\"
 
@@ -196,7 +192,7 @@
 TRANSLATIONS += locale/ru.ts
 
 # This makes qmake generate translations
-isEmpty(QMAKE_LRELEASE):QMAKE_LRELEASE = $$[QT_INSTALL_BINS]/lrelease
+isEmpty(QMAKE_LRELEASE):QMAKE_LRELEASE = $$[QT_INSTALL_BINS]/lrelease-qt4
 TS_OUT = $$TRANSLATIONS
 TS_OUT ~= s/.ts/.qm
 TSQM.name = lrelease \
