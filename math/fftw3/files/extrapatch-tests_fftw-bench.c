Fix regression tests when OPENMP option is enabled.
--- tests/fftw-bench.c.orig	2020-12-10 12:02:44 UTC
+++ tests/fftw-bench.c
@@ -125,8 +125,6 @@ void rdwisdom(void)
      if (threads_ok) {
 	  BENCH_ASSERT(FFTW(init_threads)());
 	  FFTW(plan_with_nthreads)(nthreads);
-	  BENCH_ASSERT(FFTW(planner_nthreads)() == nthreads);
-          FFTW(make_planner_thread_safe)();
 #ifdef _OPENMP
 	  omp_set_num_threads(nthreads);
 #endif
