--- iiimxcf/htt_xbe/src/watchdog.c.orig	Sat Dec  6 05:54:41 2003
+++ iiimxcf/htt_xbe/src/watchdog.c	Sat Dec  6 06:01:13 2003
@@ -187,7 +187,11 @@
    * Setup the signal handlers to monitor htt_server, htt_props
    * abnormal termination
    */
+#if defined(__FreeBSD__)
+  setsid();
+#else
   grpid = setpgrp();
+#endif
 
 #ifdef SunOS
   sigset(SIGTERM, clean_up);
@@ -309,7 +313,7 @@
   XChangeProperty(display, httw_id, class_atom, XA_STRING, 8,
 		  PropModeReplace, "htt", strlen("htt"));
 
-  XSetWMProtocols(display, httw_id, &htt_save_atom, 3);
+  XSetWMProtocols(display, httw_id, htt_save_atom, 3);
 
   XSelectInput(display, httw_id, PropertyChangeMask | StructureNotifyMask);
   XSetSelectionOwner(display, htt_atom, httw_id, CurrentTime);
@@ -703,7 +707,11 @@
      * most of the cases
      */
     sleep(1);
+#if defined(__FreeBSD__)
+    setsid();
+#else
     setpgrp();
+#endif
 #ifdef SunOS
     if (flag == OPENWIN_PATH) {
       putenv(OPENWIN_MOTIF_PRELOAD_ENV);
@@ -734,7 +742,11 @@
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
