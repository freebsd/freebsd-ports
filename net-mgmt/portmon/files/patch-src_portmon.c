--- src/portmon.c.orig	2003-08-23 06:01:10 UTC
+++ src/portmon.c
@@ -35,6 +35,18 @@
 #include <getopt.h>
 #endif
 
+int report_flag;
+int daemonize_flag;
+
+struct host_struct *hosts;
+
+char *err_msg;
+char logfile[STRLARGE];
+int timeout;
+int verbose;
+
+
+
 void version(void)
 {
  printf("This is %s, version %s\n", PACKAGE, VERSION);
