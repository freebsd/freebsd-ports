--- include/sort_r.h.orig	2022-09-02 14:58:13 UTC
+++ include/sort_r.h
@@ -25,10 +25,10 @@ Slightly modified to work with hashcat to no falsly de
 */
 
 #if (defined __APPLE__ || defined __MACH__ || defined __DARWIN__ || \
-     defined __FreeBSD__ || defined __DragonFly__ || defined __NetBSD__)
+     (defined __FreeBSD__ && !defined(qsort_r)) || defined __DragonFly__ || defined __NetBSD__)
 #  define _SORT_R_BSD
 #  define _SORT_R_INLINE inline
-#elif (defined __linux__) || defined (__CYGWIN__)
+#elif (defined __linux__) || defined (__CYGWIN__) || (defined (__FreeBSD__) && defined(qsort_r))
 #  define _SORT_R_LINUX
 #  define _SORT_R_INLINE inline
 #elif (defined _WIN32 || defined _WIN64 || defined __WINDOWS__)
@@ -167,7 +167,7 @@ static _SORT_R_INLINE void sort_r_simple(void *base, s
   #if defined _SORT_R_LINUX
 
     typedef int(* __compar_d_fn_t)(const void *, const void *, void *);
-    extern void qsort_r(void *base, size_t nel, size_t width,
+    extern void (qsort_r)(void *base, size_t nel, size_t width,
                         __compar_d_fn_t __compar, void *arg)
       __attribute__((nonnull (1, 4)));
 
@@ -186,7 +186,7 @@ static _SORT_R_INLINE void sort_r_simple(void *base, s
         /* no qsort_r in glibc before 2.8, need to use nested qsort */
         sort_r_simple(base, nel, width, compar, arg);
 
-      #elif defined __GLIBC__
+      #elif defined __GLIBC__ || (defined(__FreeBSD__) && defined(qsort_r))
 
         qsort_r(base, nel, width, compar, arg);
 
