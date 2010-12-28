--- ./goldendict.pro.orig	2010-12-04 00:12:46.000000000 +0300
+++ ./goldendict.pro	2010-12-28 11:46:37.207723741 +0300
@@ -58,12 +58,12 @@
 	ogg \
 	hunspell
     LIBS += -lX11 \
-        -lXtst
+        -lXtst -lexecinfo
     PREFIX = $$(PREFIX)
     isEmpty( PREFIX ):PREFIX = /usr/local
-    DEFINES += PROGRAM_DATA_DIR=\\\"$$PREFIX/share/apps/goldendict/\\\"
+    DEFINES += PROGRAM_DATA_DIR=\\\"$$PREFIX/share/goldendict/\\\"
     target.path = $$PREFIX/bin/
-    locale.path = $$PREFIX/share/apps/goldendict/locale/
+    locale.path = $$PREFIX/share/goldendict/locale/
     locale.files = locale/*.qm
     INSTALLS += target \
         locale
@@ -72,13 +72,15 @@
     INSTALLS += icons
     icons2.path = $$PREFIX/share/app-install/icons
     icons2.files = redist/icons/*.*
-    INSTALLS += icons2
+    # we don't use icons2 directory at FreeBSD
+    #INSTALLS += icons2
     desktops.path = $$PREFIX/share/applications
     desktops.files = redist/*.desktop
     INSTALLS += desktops
     desktops2.path = $$PREFIX/share/app-install/desktop
     desktops2.files = redist/*.desktop
-    INSTALLS += desktops2
+    # we don't use desktop2 directory at FreeBSD
+    #INSTALLS += desktops2
 }
 DEFINES += PROGRAM_VERSION=\\\"$$VERSION\\\"
 
@@ -267,8 +269,6 @@
 }
 
 # This makes qmake generate translations
-win32:# Windows doesn't seem to have *-qt4 symlinks
-isEmpty(QMAKE_LRELEASE):QMAKE_LRELEASE = $$[QT_INSTALL_BINS]/lrelease
 isEmpty(QMAKE_LRELEASE):QMAKE_LRELEASE = $$[QT_INSTALL_BINS]/lrelease-qt4
 updateqm.input = TRANSLATIONS
 updateqm.output = ${QMAKE_FILE_PATH}/${QMAKE_FILE_BASE}.qm
