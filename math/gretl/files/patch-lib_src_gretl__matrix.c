--- lib/src/gretl_matrix.c.orig	2026-08-29 19:43:08 UTC
+++ lib/src/gretl_matrix.c
@@ -335,11 +335,11 @@ static void maybe_force_single (int n, int thresh, int
     *save_nt = gretl_get_omp_threads();
 # ifdef WIN32
     if (*save_nt > 1) {
-        omp_set_num_threads(1);
+	gretl_set_omp_threads(1);
     }
 # else
     if (*save_nt > 1 && n < thresh) {
-        omp_set_num_threads(1);
+	gretl_set_omp_threads(1);
     }
 # endif
 }
@@ -8744,7 +8744,7 @@ int cholesky_factor_of_inverse (gretl_matrix *a)
         err = (info > 0)? E_NOTPD : E_DATA;
     }
 
-#if LIMIT_THREADS
+#if LIMIT_THREADS && defined(_OPENMP)
     if (save_nt > 1) {
         omp_set_num_threads(save_nt);
     }
@@ -9426,7 +9426,7 @@ int gretl_invert_general_matrix (gretl_matrix *a)
 
  bailout:
 
-#if LIMIT_THREADS
+#if LIMIT_THREADS && defined(_OPENMP)
     if (save_nt > 1) {
         omp_set_num_threads(save_nt);
     }
@@ -9770,7 +9770,7 @@ static int real_invert_symmetric_matrix (gretl_matrix 
         }
     }
 
-#if LIMIT_THREADS
+#if LIMIT_THREADS && defined(_OPENMP)
     if (save_nt > 1) {
         omp_set_num_threads(save_nt);
     }
