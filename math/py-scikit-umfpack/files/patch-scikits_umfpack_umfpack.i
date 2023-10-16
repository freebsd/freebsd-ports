--- scikits/umfpack/umfpack.i.orig	2017-10-25 11:44:24 UTC
+++ scikits/umfpack/umfpack.i
@@ -6,6 +6,8 @@
 /*
   See umfpack.py for more information.
 
+  Patched from <https://github.com/scikit-umfpack/scikit-umfpack/pull/80/files>
+
   Created by: Robert Cimrman
 */
 
@@ -218,18 +220,21 @@ CONF_IN( UMFPACK_INFO )
 };
 
 %include <umfpack.h>
-%include <umfpack_solve.h>
-%include <umfpack_defaults.h>
-%include <umfpack_triplet_to_col.h>
-%include <umfpack_col_to_triplet.h>
-%include <umfpack_transpose.h>
-%include <umfpack_scale.h>
 
-%include <umfpack_report_symbolic.h>
-%include <umfpack_report_numeric.h>
-%include <umfpack_report_info.h>
-%include <umfpack_report_control.h>
+#if UMFPACK_MAIN_VERSION < 6
+  %include <umfpack_solve.h>
+  %include <umfpack_defaults.h>
+  %include <umfpack_triplet_to_col.h>
+  %include <umfpack_col_to_triplet.h>
+  %include <umfpack_transpose.h>
+  %include <umfpack_scale.h>
 
+  %include <umfpack_report_symbolic.h>
+  %include <umfpack_report_numeric.h>
+  %include <umfpack_report_info.h>
+  %include <umfpack_report_control.h>
+#endif
+
 /*
   The order is important below!
 */
@@ -240,21 +245,22 @@ OPAQUE_ARGOUT( void * )
     void **Numeric
 }
 
-%include <umfpack_symbolic.h>
-%include <umfpack_numeric.h>
+#if UMFPACK_MAIN_VERSION < 6
+  %include <umfpack_symbolic.h>
+  %include <umfpack_numeric.h>
+#endif
 
-
 OPAQUE_ARGINOUT( void * )
 %apply  void ** opaque_arginout {
     void **Symbolic,
     void **Numeric
 }
 
-%include <umfpack_free_symbolic.h>
-%include <umfpack_free_numeric.h>
+#if UMFPACK_MAIN_VERSION < 6
+  %include <umfpack_free_symbolic.h>
+  %include <umfpack_free_numeric.h>
+#endif
 
-
-
 /*
  * wnbell - attempt to get L,U,P,Q out
  */
@@ -280,8 +286,11 @@ OPAQUE_ARGINOUT( void * )
     SuiteSparse_long *n_col,
     SuiteSparse_long *nz_udiag
 };
-%include <umfpack_get_lunz.h>
 
+#if UMFPACK_MAIN_VERSION < 6
+  %include <umfpack_get_lunz.h>
+#endif
+
 ARRAY_IN( double, double, DOUBLE )
 %apply double *array {
     double Lx [ ],
@@ -326,6 +335,8 @@ ARRAY_IN( SuiteSparse_long, SuiteSparse_long, INT64 )
 };
 %apply long *OUTPUT { SuiteSparse_long *do_recip};
 
-%include <umfpack_get_numeric.h>
-
+#if UMFPACK_MAIN_VERSION < 6
+  %include <umfpack_get_numeric.h>
 #endif
+
+#endif // SWIGPYTHON
