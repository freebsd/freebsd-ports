--- src/callbacks.c.orig	Mon Sep 17 23:20:48 2001
+++ src/callbacks.c	Mon Oct 22 15:45:26 2001
@@ -124,6 +124,10 @@
 #else
 #ifdef SOLARIS
   char *dev="/cdrom/cdrom0";
+#elif FREEBSD
+  char *dev="/dev/acd0c";
+#elif BSDfamily
+  char *dev="/dev/racd0c";
 #else
 #error "No default path."
 #endif
