--- timing.c.orig	Sat Mar 29 21:26:11 2003
+++ timing.c	Sat Mar 29 23:23:09 2003
@@ -24,7 +24,7 @@
 
 #include "draw.h"
 #include "options.h"
-#include "cpu_linux.h"
+#include "cpu_freebsd.h"
 
 void handle_timer(int sig)
 {
@@ -39,11 +39,12 @@
 {
  struct itimerval itv;
 
+ cpu_init();
  signal(SIGALRM, handle_timer);
  itv.it_value.tv_sec = 2;
  itv.it_value.tv_usec = 0;
- itv.it_interval.tv_sec = 0;
- itv.it_interval.tv_usec = opt_timer_miliseconds * 1000;
+ itv.it_interval.tv_sec = opt_timer_miliseconds / 1000;
+ itv.it_interval.tv_usec = (opt_timer_miliseconds % 1000) * 1000;
  setitimer(ITIMER_REAL, &itv, NULL);
 }
 
