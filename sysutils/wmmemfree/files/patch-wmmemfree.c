--- wmmemfree.c.orig	Fri Apr 11 12:48:52 2003
+++ wmmemfree.c	Fri Apr 11 12:50:05 2003
@@ -43,10 +43,11 @@
 {
  struct itimerval tv;
 
+ mem_init();
  tv.it_value.tv_sec = 2; /* give 2 seconds for safety */
  tv.it_value.tv_usec = 0;
- tv.it_interval.tv_sec = 0;
- tv.it_interval.tv_usec = opt_milisecs * 1000;
+ tv.it_interval.tv_sec = opt_milisecs / 1000;
+ tv.it_interval.tv_usec = (opt_milisecs % 1000) * 1000;
  signal(SIGALRM, handle_timer);
  setitimer(ITIMER_REAL, &tv, NULL);
 }
