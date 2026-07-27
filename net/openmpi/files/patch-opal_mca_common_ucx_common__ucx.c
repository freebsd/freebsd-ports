--- opal/mca/common/ucx/common_ucx.c.orig	2026-02-23 20:21:11 UTC
+++ opal/mca/common/ucx/common_ucx.c
@@ -31,6 +31,9 @@
 #include "mpi.h"
 
 #include <fnmatch.h>
+#ifdef HAVE_LIBGEN_H
+#include <libgen.h>
+#endif
 #include <stdio.h>
 #include <ucm/api/ucm.h>
 
