--- qFlipper.pro.orig	2022-11-27 06:24:58 UTC
+++ qFlipper.pro
@@ -1,7 +1,6 @@ SUBDIRS += \
 TEMPLATE = subdirs
 
 SUBDIRS += \
-    3rdparty \
     application \
     backend \
     dfu \
@@ -11,4 +10,3 @@ cli.depends = backend
 backend.depends = dfu plugins
 application.depends = backend
 cli.depends = backend
-plugins.depends = 3rdparty
