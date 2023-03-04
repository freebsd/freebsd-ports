--- src/sort_r.h.orig	2023-03-04 06:08:43 UTC
+++ src/sort_r.h
@@ -24,11 +24,12 @@ void sort_r(void *base, size_t nel, size_t width,
      defined OpenBSD3_1 || defined OpenBSD3_9 || defined __OpenBSD__ || \
      defined __NetBSD__ || \
      defined __DragonFly__ || \
-     defined AMIGA)
+     defined AMIGA) && !defined(qsort_r)
 #  define _SORT_R_BSD
 #elif (defined _GNU_SOURCE || defined __gnu_hurd__ || defined __GNU__ || \
        defined __linux__ || defined __MINGW32__ || defined __GLIBC__ || \
-       defined __CYGWIN__)
+       defined __CYGWIN__) || \
+       defined(qsort_r)
 #  define _SORT_R_LINUX
 #elif (defined _WIN32 || defined _WIN64 || defined __WINDOWS__)
 #  define _SORT_R_WINDOWS
@@ -65,7 +66,7 @@ void sort_r(void *base, size_t nel, size_t width,
   #if defined _SORT_R_BSD
 
     /* BSD requires argument swap */
-    extern void qsort_r(void *base, size_t nel, size_t width, void *thunk,
+    extern void (qsort_r)(void *base, size_t nel, size_t width, void *thunk,
                         int (*compar)(void *_thunk, const void *_a, const void *_b));
 
     struct sort_r_data
@@ -83,7 +84,7 @@ void sort_r(void *base, size_t nel, size_t width,
   #elif defined _SORT_R_LINUX
 
     typedef int(* __compar_d_fn_t)(const void *, const void *, void *);
-    extern void qsort_r(void *base, size_t nel, size_t width,
+    extern void (qsort_r)(void *base, size_t nel, size_t width,
                         __compar_d_fn_t __compar, void *arg)
       __attribute__((nonnull (1, 4)));
 
