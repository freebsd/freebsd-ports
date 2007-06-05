--- src/or/config.c.orig	Mon May 28 13:11:12 2007
+++ src/or/config.c	Mon May 28 13:12:04 2007
@@ -3901,7 +3901,7 @@
 #if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
   if (server && version < LE_13B) {
     thread_unsafe = 1;
-    sad_os = "BSD variants"
+    sad_os = "BSD variants";
       }
 #elif defined(__APPLE__) || defined(__darwin__)
   if (server && version < LE_13B) {
