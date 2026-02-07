--- vde_switch.c	Sat Jan 29 15:02:08 2005
+++ vde_switch.c	Sun Jan 30 13:33:00 2005
@@ -8,7 +8,9 @@
 #include <stdlib.h>
 #include <signal.h>
 #include <fcntl.h>
+#ifndef __FreeBSD__
 #include <stdint.h>
+#endif
 #include <getopt.h>
 #include <sys/socket.h>
 #include <sys/un.h>
@@ -17,7 +19,11 @@
 #include <unistd.h>
 #include <syslog.h>
 #include <libgen.h>
+#ifdef __FreeBSD__
+#include <string.h>
+#else
 #include <endian.h>
+#endif
 #include "vde.h"
 #include "switch.h"
 #include "port.h"
@@ -95,6 +101,13 @@
   }
 }
 
+#ifdef __FreeBSD__
+static void cleanupwrapper()
+{
+    cleanup(0, NULL);
+}
+#endif
+
 void **g_fdsdata = NULL;
 int g_nfds = 0;
 int g_minfds = 0;
@@ -276,19 +289,27 @@
 
 void bind_data_socket(int fd, struct sockaddr_un *sun)
 {
+  struct timeval tv;
+
+  sun->sun_family = AF_UNIX;
+#ifdef __FreeBSD__
+  gettimeofday(&tv, NULL);
+  snprintf(sun->sun_path, sizeof(sun->sun_path), "%s.%i.%li",
+	  VDEDATSOCK, getpid(), tv.tv_usec);
+  data_socket = strdup(sun->sun_path);
+#else
   struct {
     char zero;
     int pid;
     int usecs;
   } name;
-  struct timeval tv;
 
   name.zero = 0;
   name.pid = getpid();
   gettimeofday(&tv, NULL);
   name.usecs = tv.tv_usec;
-  sun->sun_family = AF_UNIX;
   memcpy(sun->sun_path, &name, sizeof(name));
+#endif
   if(bind(fd, (struct sockaddr *) sun, sizeof(*sun)) < 0){
     printlog(LOG_ERR,"Binding to data socket %s",strerror(errno));
     exit(1);
@@ -338,7 +359,11 @@
   int tap_fd  = -1;
 #endif
 
+#ifdef __FreeBSD__
+  atexit(cleanupwrapper);
+#else
   on_exit(cleanup, NULL);
+#endif
   prog = argv[0];
   /* option parsing */
   {
