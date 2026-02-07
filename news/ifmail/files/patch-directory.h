--- iflib/directory.h.orig	1994-11-11 21:44:05 UTC
+++ iflib/directory.h
@@ -8,6 +8,7 @@
  * Written by stefan@space.s-link.de (Stefan Westerfeld)
  */
 
+#include <sys/types.h>
 #include <dirent.h>
 
 #ifdef DONT_HAVE_DIRENT
