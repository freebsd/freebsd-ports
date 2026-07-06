--- signon-ui.pro.orig	2023-10-16 20:12:00 UTC
+++ signon-ui.pro
@@ -4,8 +4,7 @@ SUBDIRS = \
 TEMPLATE = subdirs
 CONFIG += ordered
 SUBDIRS = \
-    src \
-    tests
+    src
 
 include(common-installs-config.pri)
 
