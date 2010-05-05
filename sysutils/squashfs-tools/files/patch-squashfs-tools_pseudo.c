$FreeBSD$

--- squashfs-tools/pseudo.c.orig	2009-04-05 04:01:58.000000000 +0200
+++ squashfs-tools/pseudo.c	2010-04-29 17:45:49.000000000 +0200
@@ -31,6 +31,10 @@
 #include <stdlib.h>
 #include <sys/types.h>
 
+#ifdef __FreeBSD__
+#include <sys/stat.h>
+#endif
+
 #include "pseudo.h"
 
 #ifdef SQUASHFS_TRACE
