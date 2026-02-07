--- crosti.pro.orig	2017-11-27 07:23:03 UTC
+++ crosti.pro
@@ -54,24 +54,24 @@ win32{
 unix{# deb-package data
   DESTDIR = .
   CONFIG(release,debug|release){
-    target.path = /usr/bin
-    data.path = /usr/share/crosti
+    target.path = $$PREFIX/bin
+    data.path = $$PREFIX/share/crosti
     data.files = changelog.txt \
         gpl.txt \
         readme.txt
-    icon16.path = /usr/share/icons/hicolor/16x16/apps
+    icon16.path = $$PREFIX/share/icons/hicolor/16x16/apps
     icon16.files = src/icons/16x16/crosti.png
-    icon32.path = /usr/share/icons/hicolor/32x32/apps
+    icon32.path = $$PREFIX/share/icons/hicolor/32x32/apps
     icon32.files = src/icons/32x32/crosti.png
-    icon48.path = /usr/share/icons/hicolor/48x48/apps
+    icon48.path = $$PREFIX/share/icons/hicolor/48x48/apps
     icon48.files = src/icons/48x48/crosti.png
-    iconmime32.path = /usr/share/icons/hicolor/32x32/mimetypes
+    iconmime32.path = $$PREFIX/share/icons/hicolor/32x32/mimetypes
     iconmime32.files = src/icons/32x32/text-x-cst.png
-    system.path = /usr/share/crosti/system
+    system.path = $$PREFIX/share/crosti/system
     system.files = system/*
-    shortcut.path = /usr/share/applications
+    shortcut.path = $$PREFIX/share/applications
     shortcut.files = src/crosti.desktop
-    mime.path = /usr/share/mime/packages
+    mime.path = $$PREFIX/share/mime/packages
     mime.files = src/crosti.xml
     INSTALLS += target \
         data \
