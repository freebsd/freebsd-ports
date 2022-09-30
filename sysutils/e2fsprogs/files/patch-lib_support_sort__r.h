--- lib/support/sort_r.h.orig	2021-12-30 05:54:33 UTC
+++ lib/support/sort_r.h
@@ -25,7 +25,8 @@ void sort_r(void *base, size_t nel, size_t width,
 #define _SORT_R_INLINE inline
 
 #if (defined __gnu_hurd__ || defined __GNU__ || \
-       defined __linux__ || defined __MINGW32__ || defined __GLIBC__)
+       defined __linux__ || defined __MINGW32__ || defined __GLIBC__ || \
+       defined qsort_r)
 #  define _SORT_R_LINUX
 #elif (defined __APPLE__ || defined __MACH__ || defined __DARWIN__ || \
      defined __FreeBSD__ || defined __DragonFly__)
@@ -263,7 +264,7 @@ static _SORT_R_INLINE void sort_r_simple(void *base, s
   #if defined _SORT_R_LINUX
 
     typedef int(* __compar_d_fn_t)(const void *, const void *, void *);
-    extern void qsort_r(void *base, size_t nel, size_t width,
+    extern void (qsort_r)(void *base, size_t nel, size_t width,
                         __compar_d_fn_t __compar, void *arg)
       __attribute__((nonnull (1, 4)));
 
