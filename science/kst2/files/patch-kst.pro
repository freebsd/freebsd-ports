--- ./kst.pro.orig	2010-09-27 11:32:51.000000000 +0400
+++ ./kst.pro	2010-11-13 23:53:45.113750666 +0300
@@ -9,7 +9,5 @@
     src/libkstapp \
     src/kst \
     src/d2asc \
-    src/plugins \
-    tests
+    src/plugins
 
-!win32-msvc*:SUBDIRS += tests/dirfile_maker
