--- plugins/libac3pass/ac3-iec958.c.orig	Sun Jan 19 23:22:12 2003
+++ plugins/libac3pass/ac3-iec958.c	Sun Jan 19 23:29:53 2003
@@ -21,7 +21,9 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
-#ifndef __USE_XOPEN
+#if !defined(__USE_XOPEN) && ((__FreeBSD_cc_version < 460001) || \
+                              defined(_ANSI_SOURCE)           || \
+                              defined(_POSIX_SOURCE))
 void swab(const void *from, void *to, ssize_t n);
 #endif
 #include "ac3-iec958.h"
