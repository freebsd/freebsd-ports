--- iiimxcf/htt_xbe/src/watchdog.c.orig	Tue Jul 13 07:25:40 2004
+++ iiimxcf/htt_xbe/src/watchdog.c	Sun Sep  5 05:43:59 2004
@@ -187,11 +187,15 @@
    * Setup the signal handlers to monitor htt_server, htt_props
    * abnormal termination
    */
+#if defined(__FreeBSD__)
+  setsid();
+#else
 #ifdef SETPGRP_VOID
   grpid = setpgrp();
 #else
   grpid = setpgrp(0, 0);
 #endif
+#endif
 
 #ifdef SunOS
   sigset(SIGTERM, clean_up);
@@ -708,11 +712,15 @@
      */
     sleep(1);
 
+#if defined(__FreeBSD__)
+    setsid();
+#else
 #ifdef SETPGRP_VOID
     setpgrp();
 #else
     setpgrp(0, 0);
 #endif
+#endif
 
 #ifdef SunOS
     if (flag == OPENWIN_PATH) {
@@ -744,7 +752,11 @@
     perror("watchdog:fork\n");
     exit(errno);
   case 0:
+#if defined(__FreeBSD__)
+    setsid();
+#else
     setpgrp();
+#endif
     if (!my_rdb.respond_to_sm)
       sleep(10);
     execv(pathname, argv);
