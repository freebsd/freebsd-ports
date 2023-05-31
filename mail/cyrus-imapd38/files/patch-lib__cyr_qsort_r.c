--- lib/cyr_qsort_r.c.orig	2019-12-04 02:17:01 UTC
+++ lib/cyr_qsort_r.c
@@ -18,14 +18,14 @@ EXPORTED void cyr_qsort_r(void *base, size_t nmemb, si
 // NOTE: this is kinda ugly, but it's OK if you're not multithreaded
 
 static void *qsort_r_thunk;
-static int (*qsort_r_compar)(const void *, const void *, void *);
+static int (*qsort_r_compar)QSORT_R_COMPAR_ARGS(const void *, const void *, void *);
 static int qsort_r_compar_func(const void *a, const void *b)
 {
     return qsort_r_compar(a, b, qsort_r_thunk);
 }
 
 EXPORTED void cyr_qsort_r(void *base, size_t nmemb, size_t size,
-                          int (*compar)(const void *, const void *, void *),
+                          int (*compar)QSORT_R_COMPAR_ARGS(const void *, const void *, void *),
                           void *thunk)
 {
     qsort_r_thunk = thunk;
