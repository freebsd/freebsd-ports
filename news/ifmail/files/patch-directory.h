--- iflib/directory.h.orig	Sat Nov 15 16:22:07 1997
+++ iflib/directory.h	Sat Nov 15 16:22:17 1997
@@ -8,6 +8,7 @@
  * Written by stefan@space.s-link.de (Stefan Westerfeld)
  */
 
+#include <sys/types.h>
 #include <dirent.h>
 
 #ifdef DONT_HAVE_DIRENT
