--- src/portmon.h.orig	2003-08-23 06:04:38 UTC
+++ src/portmon.h
@@ -31,8 +31,8 @@
 #define STRLARGE 512
 
 // flags
-int report_flag;
-int daemonize_flag;
+extern int report_flag;
+extern int daemonize_flag;
 
 struct port
 {
@@ -48,17 +48,17 @@ struct host_struct
   char name[STRMED];
   struct port ports[STRSMALL];
   int num_ports;
-}
- *hosts;
+};
+extern struct host_struct *hosts;
 
 // place to hold error messages
-char *err_msg;
+extern char *err_msg;
 // place we log crap
-char logfile[STRLARGE];
+extern char logfile[STRLARGE];
 // timeout (seconds)
-int timeout;
+extern int timeout;
 // verbose mode
-int verbose;
+extern int verbose;
 
 // Functions in various files
 
