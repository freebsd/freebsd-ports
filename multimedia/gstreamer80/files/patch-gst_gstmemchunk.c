--- gst/gstmemchunk.c.orig	Wed Aug  4 15:31:41 2004
+++ gst/gstmemchunk.c	Wed Aug  4 15:31:52 2004
@@ -24,6 +24,7 @@
 #include "gstmemchunk.h"
 #include "gsttrashstack.h"
 #ifdef HAVE_VALGRIND
+#include <sys/types.h>
 #include <sys/mman.h>
 #include <valgrind/valgrind.h>
 #endif
