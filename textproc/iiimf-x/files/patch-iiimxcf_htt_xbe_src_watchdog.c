--- iiimxcf/htt_xbe/src/watchdog.c	Tue Jul 13 08:25:40 2004
+++ iiimxcf/htt_xbe/src/watchdog.c	Wed Feb 16 19:12:34 2005
@@ -81,7 +81,6 @@
 #endif
 #define OPENWIN_MOTIF_PRELOAD_ENV "LD_PRELOAD=/usr/dt/lib/libXm.so.3"
 
-#define IMDIR "/usr/lib/im"
 
 static void     start_htt_server(int *, char *argv[]);
 static void     start_htt_props(int *, char *argv[]);
@@ -744,7 +743,11 @@
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
