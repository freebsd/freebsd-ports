--- src/dc_com.c.orig	Thu Nov 22 00:12:50 2001
+++ src/dc_com.c	Thu Nov 22 00:15:55 2001
@@ -33,6 +33,15 @@
 #include "main.h"
 #include "var.h"
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
+#if (defined(BSD) && (BSD >= 199103))
+#include <signal.h>
+#define MSG_NOSIGNAL 0
+#endif
+
 char last_cmd[5120];			/* contains the first string of the last send_dc_line call */
 									/* mainly used for debug features.                         */
 time_t last_cmd_time;
@@ -50,6 +59,10 @@
 /***********************************************************/
 void send_dc_line(int sck,...)
 {
+#if (defined(BSD) && (BSD >= 199103))
+	sigset_t sigset, sigoset;
+	ssize_t send_return;
+#endif
 	va_list ap;
 	char *t;
 	int have=0;
@@ -84,7 +97,21 @@
 
 	if((str->len)&&(cnx_in_progress==0))
 	{
-		if(send(sck,str->str,str->len,MSG_NOSIGNAL)!=str->len)
+#if (defined(BSD) && (BSD >= 199103))
+		/* possible race condition since backup and restore
+		are not guaranteed to occur as a single operation */
+
+		/* backup sigmask and block SIGPIPE */
+		sigemptyset(&sigset);
+		sigaddset(&sigset,SIGPIPE);
+		(void) sigprocmask(SIG_BLOCK, &sigset, &sigoset);
+#endif
+		send_return = send(sck,str->str,str->len, MSG_NOSIGNAL);
+#if (defined(BSD) && (BSD >= 199103))
+		/* restore sigmask backup */
+		(void)sigprocmask(SIG_SETMASK, &sigoset, NULL);
+#endif
+		if(send_return!=str->len)
 		{
 			/* abort network operation on this socket */
 			/* this will either generated a hub_disconnection message (main thread) */
