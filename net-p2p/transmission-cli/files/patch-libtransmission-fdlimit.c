--- libtransmission/fdlimit.c.orig	2012-04-09 02:51:33.750482000 +0100
+++ libtransmission/fdlimit.c	2012-06-06 13:31:54.992362170 +0100
@@ -21,9 +21,7 @@
 #include <errno.h>
 #include <inttypes.h>
 #include <string.h>
-#ifdef SYS_DARWIN
- #include <fcntl.h>
-#endif
+#include <fcntl.h>
 
 #ifdef HAVE_FALLOCATE64
   /* FIXME can't find the right #include voodoo to pick up the declaration.. */
