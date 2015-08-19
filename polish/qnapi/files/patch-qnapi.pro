--- qnapi.pro.orig	2015-08-08 19:45:00 UTC
+++ qnapi.pro
@@ -118,7 +118,7 @@ macx { 
 }
 
 unix { 
-    INSTALL_PREFIX = /usr
+    INSTALL_PREFIX = $${PREFIX}
     target.path = $${INSTALL_PREFIX}/bin
     doc.path = $${INSTALL_PREFIX}/share/doc/$${TARGET}
     doc.files = doc/ChangeLog \
@@ -129,17 +129,16 @@ unix { 
         doc/qnapi-scan.desktop \
         doc/qnapi-download.schemas \
         doc/qnapi-scan.schemas
-    man.path = $${INSTALL_PREFIX}/share/man/man1
+    man.path = $${INSTALL_PREFIX}/man/man1
     man.files = doc/$${TARGET}.1.gz
-    icons.path = /usr/share/icons
+    icons.path = $${INSTALL_PREFIX}/share/icons
     icons.files = res/qnapi.png \
         res/qnapi-48.png \
         res/qnapi-128.png \
         res/qnapi-512.png
-    desktop.path = /usr/share/applications
+    desktop.path = $${INSTALL_PREFIX}/share/applications
     desktop.files = doc/$${TARGET}.desktop
     INSTALLS = target \
-        doc \
         man \
         icons \
         desktop
