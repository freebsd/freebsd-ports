--- src/db.c.orig	Thu Nov 22 00:08:34 2001
+++ src/db.c	Thu Nov 22 00:11:49 2001
@@ -30,6 +30,15 @@
 #include <netinet/in.h>
 #include <glib.h>
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
+#if (defined(BSD) && (BSD >= 199103))
+#include <signal.h>
+#define MSG_NOSIGNAL 0
+#endif
+
 #include "db.h"
 #include "display.h"
 #include "var.h"
@@ -711,6 +720,9 @@
 /******************************************************************************************/
 static void send_a_db_result(int output_sck, char *dest_nick, DB_ENTRY *de, struct sockaddr_in *dest_addr, char *md5sum)
 {
+#if (defined(BSD) && (BSD >= 199103))
+	sigset_t sigset, sigoset;
+#endif
 	GString *str;
 	GString *adapted;
 
@@ -752,10 +764,38 @@
 	printf("dest_addr: %s, str: %s\n",dest_addr,str->str);
 #endif
 
-	if(dest_addr==NULL)
+	if(dest_addr==NULL) {
+#if (defined(BSD) && (BSD >= 199103))
+	/* possible race condition since backup and restore
+	are not guaranteed to occur as a single operation */
+
+	/* backup sigmask and block SIGPIPE */
+	sigemptyset(&sigset);
+	sigaddset(&sigset,SIGPIPE);
+	(void) sigprocmask(SIG_BLOCK, &sigset, &sigoset);
+#endif
 		send(output_sck,str->str,str->len,MSG_NOSIGNAL);
-	else
+#if (defined(BSD) && (BSD >= 199103))
+		/* restore sigmask backup */
+		(void)sigprocmask(SIG_SETMASK, &sigoset, NULL);
+#endif
+	} else {
+#if (defined(BSD) && (BSD >= 199103))
+	/* possible race condition since backup and restore
+	are not guaranteed to occur as a single operation */
+
+	/* backup sigmask and block SIGPIPE */
+	sigemptyset(&sigset);
+	sigaddset(&sigset,SIGPIPE);
+	(void) sigprocmask(SIG_BLOCK, &sigset, &sigoset);
+#endif
 		sendto(output_sck,str->str,str->len,MSG_NOSIGNAL,(void*)dest_addr, sizeof(struct sockaddr_in));
+
+#if (defined(BSD) && (BSD >= 199103))
+		/* restore sigmask backup */
+		(void)sigprocmask(SIG_SETMASK, &sigoset, NULL);
+#endif
+	}
 
 	disp_msg(INFO_MSG,"send_search_result_line",str->str,NULL);
 
