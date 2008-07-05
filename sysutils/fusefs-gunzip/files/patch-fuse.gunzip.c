--- fuse.gunzip.c.orig    2007-03-21 01:19:26.000000000 +0300
+++ fuse.gunzip.c    2008-06-16 01:46:43.000000000 +0400
@@ -38,9 +38,6 @@
 #include <config.h>
 */

-#define HAVE_SETXATTR 1
-#define HAVE_FDATASYNC 1
-
 #define _GNU_SOURCE

 #include <fuse.h>
