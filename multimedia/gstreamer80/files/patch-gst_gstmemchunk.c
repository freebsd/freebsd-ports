--- gst/gstmemchunk.c.orig	Thu Jun 24 16:30:43 2004
+++ gst/gstmemchunk.c	Thu Jun 24 16:30:52 2004
@@ -24,6 +24,7 @@
 #include "gstmemchunk.h"
 #include "gsttrashstack.h"
 #ifdef HAVE_VALGRIND
+#include <sys/types.h>
 #include <sys/mman.h>
 #include <valgrind/valgrind.h>
 #endif
