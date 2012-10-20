--- libbitdht/src/libbitdht.pro.orig	2012-08-16 18:59:51.000000000 +0200
+++ libbitdht/src/libbitdht.pro	2012-10-08 18:41:49.000000000 +0200
@@ -91,6 +91,7 @@
 
 freebsd-* {
 		DESTDIR = lib
+		INCLUDEPATH += ../../openpgpsdk/src \
 }
 
 ################################### COMMON stuff ##################################
