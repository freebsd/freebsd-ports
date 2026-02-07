--- tests/test_main.c.orig	2003-03-17 08:43:46.000000000 +0900
+++ tests/test_main.c	2012-03-12 22:47:45.000000000 +0900
@@ -548,7 +548,7 @@
 void test_timer(void)
 {
      double times[32], acc, min_time = 10000.00;
-     unsigned long iters, iter;
+     unsigned long iters = 0, iter;
      fftw_time begin, end, start;
      double t, tmax, tmin;
      int last = 0, i, repeat;
@@ -559,7 +559,8 @@
      start = fftw_get_time();
 
      for (i = 0; i < 32; i++) {
-	  iters = 1 << i;
+	  //iters = 1 << i; /* workaround gcc-4.1 bug */
+	  if (i) iters <<= 1; else iters = 1;
 	  tmin = 1.0E10;
 	  tmax = -1.0E10;
 
