--- l2tpd.c.orig	Mon Aug 19 17:12:17 2002
+++ l2tpd.c	Sat Nov 23 19:12:09 2002
@@ -34,8 +34,6 @@
 #include <netdb.h>
 #include <string.h>
 #include <fcntl.h>
-#include <netinet/in.h>
-#include <arpa/inet.h>
 #ifdef USE_KERNEL
 #include <sys/ioctl.h>
 #endif
@@ -46,6 +44,7 @@
 struct utsname uts;
 int ppd = 1;                    /* Packet processing delay */
 int control_fd;                 /* descriptor of control area */
+int control_fdw;                 /* descriptor of control area */
 char *args;
 
 char *dial_no_tmp;              /* jz: Dialnumber for Outgoing Call */
@@ -384,6 +384,7 @@
 
         /* close the control pipe fd */
         close (control_fd);
+	close (control_fdw);
 
         execv (PPPD, stropt);
         log (LOG_WARN, "%s: Exec of %s failed!\n", __FUNCTION__, PPPD);
@@ -764,8 +765,8 @@
     struct lac *lac;
     int call;
     int tunl;
-    int cnt = -1;
-    while (cnt)
+    int cnt = 1;
+    while (cnt > 0)
     {
         cnt = read (control_fd, buf, sizeof (buf));
         if (cnt > 0)
@@ -920,7 +921,9 @@
     }
     /* Otherwise select goes nuts */
     close (control_fd);
+    close (control_fdw);
     control_fd = open (CONTROL_PIPE, O_RDONLY | O_NONBLOCK, 0600);
+    control_fdw = open (CONTROL_PIPE, O_WRONLY | O_NONBLOCK, 0600);
 }
 
 void usage(void) {
@@ -985,6 +988,7 @@
     char buf[STRLEN];
     int pidfilewritten=0;
 
+#ifndef __FreeBSD__
     if((pid = fork()) < 0) {
         log(LOG_LOG, "%s: Unable to fork ()\n",__FUNCTION__);
         close(server_socket);
@@ -998,6 +1002,12 @@
                          to do a proper fix for this */
     close(1);
     close(2);
+#else
+    if (daemon(0, 0) != 0) {
+	log(LOG_LOG, "%s: daemon () failed\n", __FUNCTION__);
+	exit(1);
+    }
+#endif
 
     /* Read previous pid file. */
     if ((i = open(gconfig.pidfile,O_RDONLY)) > 0) {
@@ -1075,6 +1085,7 @@
     init_scheduler ();
     mkfifo (CONTROL_PIPE, 0600);
     control_fd = open (CONTROL_PIPE, O_RDONLY | O_NONBLOCK, 0600);
+    control_fdw = open (CONTROL_PIPE, O_WRONLY | O_NONBLOCK, 0600);
     if (control_fd < 0)
     {
         log (LOG_CRIT, "%s: Unable to open " CONTROL_PIPE " for reading.",
