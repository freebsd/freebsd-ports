--- ./boinc_curses.c.orig	2012-05-25 14:18:33.000000000 +0200
+++ ./boinc_curses.c	2013-09-27 10:23:19.000000000 +0200
@@ -21,6 +21,7 @@
 
 #include <curses.h>
 #include <signal.h>
+#include <time.h>
 #include <sys/ioctl.h>
 
 #include <gui_rpc_client.h>
