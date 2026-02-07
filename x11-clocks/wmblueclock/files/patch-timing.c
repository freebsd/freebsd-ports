--- timing.c.orig	Fri Apr 25 04:34:40 2003
+++ timing.c	Fri Apr 25 04:35:03 2003
@@ -38,8 +38,8 @@
  signal(SIGALRM, handle_timer);
  itv.it_value.tv_sec = 2;
  itv.it_value.tv_usec = 0;
- itv.it_interval.tv_sec = 0;
- itv.it_interval.tv_usec = opt_milisecs * 1000;
+ itv.it_interval.tv_sec = opt_milisecs / 1000;
+ itv.it_interval.tv_usec = (opt_milisecs % 1000) * 1000;
  setitimer(ITIMER_REAL, &itv, NULL);
 }
 
