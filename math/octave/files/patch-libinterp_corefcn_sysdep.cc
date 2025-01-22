--- libinterp/corefcn/sysdep.cc.orig	2024-12-12 11:30:00 UTC
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
@@ -110,6 +114,9 @@ BSD_init ()
 static void
 BSD_init ()
 {
+#if defined(__FreeBSD__) && defined(__arm__)
+  fedisableexcept(FE_ALL_EXCEPT);
+#else /* !defined(__FreeBSD__) || !defined(__arm__) */
 #  if defined (HAVE_FLOATINGPOINT_H)
   // Disable trapping on common exceptions.
 #    if ! defined (FP_X_DNML)
@@ -117,6 +124,7 @@ BSD_init ()
 #    endif
   fpsetmask (~(FP_X_OFL|FP_X_INV|FP_X_DZ|FP_X_DNML|FP_X_UFL|FP_X_IMP));
 #  endif
+#endif
 }
 
 #endif
