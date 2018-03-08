--- libinterp/corefcn/sysdep.cc.orig	2018-03-08 03:49:02 UTC
+++ libinterp/corefcn/sysdep.cc
@@ -61,6 +61,10 @@ along with Octave; see the file COPYING.
 #  include <omp.h>
 #endif
 
+#if defined (__FreeBSD__) && defined(__arm__)
+#include <fenv.h>
+#endif
+
 #include "cmd-edit.h"
 #include "file-ops.h"
 #include "lo-mappers.h"
@@ -97,6 +101,7 @@ along with Octave; see the file COPYING.
 static void
 BSD_init (void)
 {
+#if (defined (__FreeBSD__) && !defined(__arm__))
 #  if defined (HAVE_FLOATINGPOINT_H)
   // Disable trapping on common exceptions.
 #    if ! defined (FP_X_DNML)
@@ -104,6 +109,9 @@ BSD_init (void)
 #    endif
   fpsetmask (~(FP_X_OFL|FP_X_INV|FP_X_DZ|FP_X_DNML|FP_X_UFL|FP_X_IMP));
 #  endif
+#else // FreeBSD && arm
+  fedisableexcept(FE_ALL_EXCEPT);
+#endif // FreeBSD && arm
 }
 #endif
 
