--- iiimsf/src/watchdog.c	Thu Oct 14 23:07:37 2004
+++ iiimsf/src/watchdog.c	Wed Feb 16 19:03:59 2005
@@ -220,7 +220,7 @@
     int		argc;
     char	**argv;
 {
-    const char *httpath="/usr/lib/im/htt_server" ; /* SUNWiiimf Only */
+    const char *httpath=IM_DIRECTORY "/htt_server" ; /* SUNWiiimf Only */
     pid_t pgrp;
     void (*disp)(int);
     char **new_argv, **pp;
@@ -361,6 +361,8 @@
     if ((pid_t)(-1) == pgrp)
       fprintf (stderr,"cannot set session id");
 
+#elif defined(__FreeBSD__)
+    pgrp = setsid();
 #else /* !SunOS */
     pgrp = setpgrp(); 
 #endif /* !SunOS */
