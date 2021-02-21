--- libinterp/corefcn/sysdep.cc.orig	2020-11-26 18:20:44 UTC
+++ libinterp/corefcn/sysdep.cc
@@ -61,6 +61,10 @@
 #  include <omp.h>
 #endif
 
+#if defined (__FreeBSD__) && defined(__arm__)
+#include <fenv.h>
+#endif
+
 #include "cmd-edit.h"
 #include "file-ops.h"
 #include "lo-mappers.h"
