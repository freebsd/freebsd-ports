--- udpr-negotiate.c.orig	Sat Feb 21 14:08:49 2004
+++ udpr-negotiate.c	Tue Jul 20 13:44:05 2004
@@ -2,6 +2,10 @@
 #include <unistd.h>
 #include <errno.h>
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #include "log.h"
 #include "socklib.h"
 #include "udpcast.h"
@@ -16,6 +20,10 @@
 # define O_BINARY 0
 #endif
 
+#ifdef __FreeBSD__
+struct client_config client_config_on_exit_hack;
+#endif
+
 static int sendConnectReq(struct client_config *client_config,
 			  struct net_config *net_config,
 			  int haveServerAddress) {
@@ -48,6 +56,12 @@
     sendDisconnect(exitStatus, (struct client_config *) args);
 }
 
+#ifdef __FreeBSD__
+static void sendDisconnectWrapper_on_exit_handler() {
+    sendDisconnectWrapper(0, &client_config_on_exit_hack);
+}
+#endif
+
 void sendDisconnect(int exitStatus,
 		    struct client_config *client_config) {    
     int endianness = client_config->endianness;
@@ -144,7 +158,7 @@
     if(disk_config->fileName != NULL) {
 	int oflags = O_CREAT | O_WRONLY;
 	if(!(disk_config->flags & FLAG_NOSYNC)) {
-	    oflags |= O_SYNC;
+	    oflags |= O_FSYNC;
 	}
 	outFile = open(disk_config->fileName, oflags | O_BINARY, 0644);
 	if(outFile < 0) {
@@ -333,7 +347,13 @@
     pipedOutFile = openPipe(client_config.toServer, outFile, disk_config,
 			    &pipePid);
 #ifndef __CYGWIN__
+# ifdef __FreeBSD__
+    client_config_on_exit_hack = client_config;
+
+    atexit(sendDisconnectWrapper_on_exit_handler);
+# else
     on_exit(sendDisconnectWrapper, &client_config);
+# endif
 #endif
     {
 	struct fifo fifo;
