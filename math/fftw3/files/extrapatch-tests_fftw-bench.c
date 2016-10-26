Fix regression tests when OPENMP option is enabled.
--- tests/fftw-bench.c.orig	2016-10-25 22:27:48 UTC
+++ tests/fftw-bench.c
@@ -110,7 +110,6 @@ void rdwisdom(void)
      if (threads_ok) {
 	  BENCH_ASSERT(FFTW(init_threads)());
 	  FFTW(plan_with_nthreads)(nthreads);
-          FFTW(make_planner_thread_safe)();
 #ifdef _OPENMP
 	  omp_set_num_threads(nthreads);
 #endif
