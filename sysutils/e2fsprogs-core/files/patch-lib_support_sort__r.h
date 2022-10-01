--- lib/support/sort_r.h.orig	2021-12-30 05:54:33 UTC
+++ lib/support/sort_r.h
@@ -234,10 +234,6 @@ static _SORT_R_INLINE void sort_r_simple(void *base, s
 
   #if defined _SORT_R_BSD
 
-    /* Ensure qsort_r is defined */
-    extern void qsort_r(void *base, size_t nel, size_t width, void *thunk,
-                        int (*compar)(void *_thunk,
-                                      const void *_a, const void *_b));
 
   #endif
 
@@ -262,10 +258,6 @@ static _SORT_R_INLINE void sort_r_simple(void *base, s
 
   #if defined _SORT_R_LINUX
 
-    typedef int(* __compar_d_fn_t)(const void *, const void *, void *);
-    extern void qsort_r(void *base, size_t nel, size_t width,
-                        __compar_d_fn_t __compar, void *arg)
-      __attribute__((nonnull (1, 4)));
 
   #endif
 
