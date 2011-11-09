
$FreeBSD$

--- asterisk-driver/chan_oh323.c.orig
+++ asterisk-driver/chan_oh323.c
@@ -34,6 +34,7 @@
 #include <string.h>
 #include <sys/socket.h>
 #include <sys/time.h>
+#include <stdio.h>
 #include <errno.h>
 #include <unistd.h>
 #include <stdlib.h>
@@ -43,6 +44,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <math.h>
+#include <netinet/in_systm.h>
 #include <netinet/ip.h>
 #include <sys/signal.h>
 
@@ -83,6 +85,8 @@
 #include "asterisk/threadstorage.h"
 #include "asterisk/translate.h"
 
+#define CRASH abort()
+
 #include "wrapper.hxx"
 #include "oh323.h"
 
@@ -954,8 +958,8 @@
 static void oh323_format2codecset(int, int *, int);
 static int context_from_alias(char *, char **);
 static int context_from_prefix(char *, char **);
-static int oh323_release(void *);
-static int oh323_exec_request(void *data);
+static int oh323_release(const void *);
+static int oh323_exec_request(const void *data);
 static struct oh323_ep *find_oh323_ep(char *epname, char *host, char *user);
 void oh323_atexit(void);
 unsigned int generate_uid(void);
@@ -1595,6 +1599,8 @@
 			ast_log(LOG_DEBUG, "%s: Call progress.\n", c->name);
 		p->fr.frametype = AST_FRAME_CONTROL;
 		p->fr.subclass = AST_CONTROL_PROGRESS;
+/* The code below is broken with asterisk 1.4.23.1 */
+#if 0
 	/* -- Call transfer */
 	} else if (e->type == OH323EXC_CALL_TRANSFER) {
 		/* XXX Asterisk MUST read first the frame returned by this exception
@@ -1608,6 +1614,7 @@
 			memcpy(c->dtmfq, e->data, strlen(e->data));
 			write(p->event_pipe[1], notify_buf, 1);
 		}
+#endif
 	/* -- Call establishment notification */
 	} else if (e->type == OH323EXC_CALL_ESTABLISHED) {
 		memset(p->rtp.local_addr, 0, sizeof(p->rtp.local_addr));
@@ -4110,7 +4117,7 @@
 /******************************************************************************/
 /* Monitoring thread and queue call-back functions ****************************/
 
-static int oh323_exec_request(void *data)
+static int oh323_exec_request(const void *data)
 {
 	struct request_oh323 *e;
 	int res, i;
@@ -4217,7 +4224,7 @@
 	return(0);
 }
 
-static int oh323_release(void *data)
+static int oh323_release(const void *data)
 {
 	struct chan_oh323_pvt *pvt = (struct chan_oh323_pvt *)data;
 	int index;
@@ -4240,7 +4247,7 @@
 	return(0);
 }
 
-static int oh323_gk_check(void *data)
+static int oh323_gk_check(const void *data)
 {
 	char gkname[256];
 
@@ -4443,7 +4450,7 @@
 				return(-1);
 			}
 		}
-		monitor_thread = -2;
+		monitor_thread = AST_PTHREADT_STOP;
 	} else {
 		ast_log(LOG_WARNING, "Unable to lock the monitor.\n");
 		return(-1);
