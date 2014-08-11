--- src/external/thread_mpi/src/atomic.c.orig
+++ src/external/thread_mpi/src/atomic.c
@@ -35,6 +35,14 @@
    files.
  */
 
+#ifdef HAVE_TMPI_CONFIG_H
+#include "tmpi_config.h"
+#endif
+
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
+
 #include "impl.h"
 
 /* This file is only needed when no intrinsic atomic operations are present. */
