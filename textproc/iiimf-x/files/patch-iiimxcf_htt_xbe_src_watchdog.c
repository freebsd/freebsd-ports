--- iiimxcf/htt_xbe/src/watchdog.c.orig	Thu Apr 28 15:09:27 2005
+++ iiimxcf/htt_xbe/src/watchdog.c	Mon May 16 23:39:28 2005
@@ -79,7 +79,7 @@
 #ifndef OPENWINHOME
 #define OPENWINHOME "/usr/openwin"
 #endif
-#define OPENWIN_MOTIF_PRELOAD_ENV "LD_PRELOAD=/usr/dt/lib/libXm.so.3"
+#define OPENWIN_MOTIF_PRELOAD_ENV "LD_PRELOAD=/usr/X11R6/lib/libXm.so.3"
 
 #define IMDIR IIIMLIBDIR
 
@@ -811,7 +811,11 @@
     perror("watchdog:fork\n");
     exit(errno);
   case 0:
+#ifdef __FreeBSD__
+    setsid();
+#else
     setpgrp();
+#endif
     if (!my_rdb.respond_to_sm)
       sleep(10);
     execv(pathname, argv);
@@ -828,7 +832,7 @@
   extern int	errno;
   int		pid;
 
-  pathname = "/usr/bin/iiimd";
+  pathname = "%%PREFIX%%" "/bin/iiimd";
 
   pid = (*iiimd_pid) = fork();
   switch (*iiimd_pid) {
