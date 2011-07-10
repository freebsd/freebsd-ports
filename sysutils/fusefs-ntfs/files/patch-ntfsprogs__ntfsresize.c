--- ntfsprogs/ntfsresize.2	2011-04-10 20:04:41.000000000 +0200
+++ ntfsprogs/ntfsresize.c	2011-04-24 08:34:35.000000000 +0200
@@ -48,6 +48,9 @@
 #ifdef HAVE_ERRNO_H
 #include <errno.h>
 #endif
+#ifdef HAVE_LIMITS_H
+#include <limits.h>
+#endif
 #ifdef HAVE_GETOPT_H
 #include <getopt.h>
 #endif
