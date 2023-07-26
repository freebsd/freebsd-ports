--- wmmemfree.c.orig	2003-03-21 20:47:14 UTC
+++ wmmemfree.c
@@ -27,15 +27,18 @@
 #include "draw.h"
 #include "options.h"
 
+void mem_init();
+
 int    argc;
 char **argv;
 int    exitloop = 0;
+volatile sig_atomic_t need_update = 0;
 
 void handle_timer(int sig)
 {
  if(sig == SIGALRM)
  {
-  draw_window();
+  need_update = 1;
  }
 }
 
@@ -45,8 +48,8 @@ void start_timer()
 
  tv.it_value.tv_sec = 2; /* give 2 seconds for safety */
  tv.it_value.tv_usec = 0;
- tv.it_interval.tv_sec = 0;
- tv.it_interval.tv_usec = opt_milisecs * 1000;
+ tv.it_interval.tv_sec = opt_milisecs / 1000;
+ tv.it_interval.tv_usec = (opt_milisecs % 1000) * 1000;
  signal(SIGALRM, handle_timer);
  setitimer(ITIMER_REAL, &tv, NULL);
 }
@@ -69,9 +72,15 @@ int main(int carg, char **varg)
  argv = varg;
  parse_args();
  make_window();
+ mem_init();
  start_timer();
  while(!exitloop)
  {
+  if(need_update)
+  {
+   draw_window();
+   need_update = 0;
+  }
   process_events();
  }
  stop_timer();
