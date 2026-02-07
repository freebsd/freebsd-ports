--- src/libxsmm_timer.c.orig	2021-11-25 15:39:20 UTC
+++ src/libxsmm_timer.c
@@ -24,7 +24,7 @@
 # pragma offload_attribute(pop)
 #endif
 
-#if defined(__powerpc64__)
+#if defined(__powerpc64__) && defined(__GLIBC__)
 # include <sys/platform/ppc.h>
 #endif
 
@@ -37,9 +37,13 @@
 
 #if defined(LIBXSMM_TIMER_TSC)
 # if defined(__powerpc64__)
+#  if defined(__GLIBC__)
 #   define LIBXSMM_TIMER_RDTSC(CYCLE) { \
       CYCLE = __ppc_get_timebase(); \
     }
+#  else
+#   define LIBXSMM_TIMER_RDTSC(CYCLE) asm volatile("mfspr %%r3, 268": "=r" (CYCLE));
+#  endif
 # elif ((defined(__GNUC__) || defined(LIBXSMM_INTEL_COMPILER) || defined(__PGI)) && (64 <= (LIBXSMM_BITS)))
 #   define LIBXSMM_TIMER_RDTSC(CYCLE) { libxsmm_timer_tickint libxsmm_timer_rdtsc_hi_; \
       __asm__ __volatile__ ("rdtsc" : "=a"(CYCLE), "=d"(libxsmm_timer_rdtsc_hi_)); \
