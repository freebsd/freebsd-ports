--- signon-ui.pro.orig	2013-06-11 06:51:14 UTC
+++ signon-ui.pro
@@ -3,10 +3,7 @@ include(common-project-config.pri)
 
 TEMPLATE = subdirs
 CONFIG += ordered
-SUBDIRS = \
-    po \
-    src \
-    tests
+SUBDIRS = src 
 
 include(common-installs-config.pri)
 
