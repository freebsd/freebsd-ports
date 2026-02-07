--- lib/dsi.c.orig	2008-02-18 03:53:03.000000000 +0000
+++ lib/dsi.c	2012-10-14 13:12:03.000000000 +0000
@@ -19,12 +19,12 @@
 #include <signal.h>
 #include <iconv.h>
 
-#include "utils.h"
-#include "dsi.h"
-#include "afp.h"
-#include "uams_def.h"
+#include "afpfs-ng/utils.h"
+#include "afpfs-ng/dsi.h"
+#include "afpfs-ng/afp.h"
+#include "afpfs-ng/uams_def.h"
 #include "dsi_protocol.h"
-#include "libafpclient.h"
+#include "afpfs-ng/libafpclient.h"
 #include "afp_internal.h"
 #include "afp_replies.h"
 
@@ -64,7 +64,7 @@
 	rx.size=0;
 	dsi_setup_header(server,&header,DSI_DSIGetStatus);
 	/* We're intentionally ignoring the results */
-	ret=dsi_send(server,(char *) &header,sizeof(struct dsi_header),20,
+	ret=dsi_send(server,(char *) &header,sizeof(struct dsi_header),60,
 		0,(void *) &rx);
 
 	free(rx.data);
@@ -197,6 +197,7 @@
 	new_request->other=other;
 	new_request->wait=wait;
 	new_request->next=NULL;
+      	new_request->done_waiting=0;
 
 	pthread_mutex_lock(&server->request_queue_mutex);
 	if (server->command_requests==NULL) {
@@ -208,7 +209,8 @@
 	server->stats.requests_pending++;
 	pthread_mutex_unlock(&server->request_queue_mutex);
 
-	pthread_cond_init(&new_request->condition_cond,NULL);
+	pthread_cond_init(&new_request->waiting_cond,NULL);
+	pthread_mutex_init(&new_request->waiting_mutex,NULL);
 
 	if (server->connect_state==SERVER_STATE_DISCONNECTED) {
 		char mesg[1024];
@@ -240,16 +242,12 @@
 	server->stats.tx_bytes+=size;
 	pthread_mutex_unlock(&server->send_mutex);
 
-	int tmpwait=new_request->wait;
 	#ifdef DEBUG_DSI
 	printf("=== Waiting for response for %d %s\n",
 		new_request->requestid,
 		afp_get_command_name(new_request->subcommand));
 	#endif
-	if (tmpwait<0) {
-
-		pthread_mutex_t     mutex = PTHREAD_MUTEX_INITIALIZER;
-		pthread_mutex_lock(&mutex);
+	if (new_request->wait<0) {
 
 		/* Wait forever */
 		#ifdef DEBUG_DSI
@@ -258,14 +256,17 @@
 			afp_get_command_name(new_request->subcommand));
 		#endif
 
-		rc=pthread_cond_wait( 
-			&new_request->condition_cond, 
-				&mutex );
-		pthread_mutex_unlock(&mutex);
-
-	} else if (tmpwait>0) {
-		pthread_mutex_t     mutex = PTHREAD_MUTEX_INITIALIZER;
-		pthread_mutex_lock(&mutex);
+		pthread_mutex_lock(&new_request->waiting_mutex);
+
+		if (new_request->done_waiting==0)
+			rc=pthread_cond_wait( 
+				&new_request->waiting_cond, 
+					&new_request->waiting_mutex );
+
+		pthread_mutex_unlock(&new_request->waiting_mutex);
+
+	} else if (new_request->wait>0) {
+		/* wait for new_request->wait seconds */
 
 		#ifdef DEBUG_DSI
 		printf("=== Waiting for %d %s, for %ds\n",
@@ -283,13 +284,15 @@
 			printf("=== Changing my mind, no longer waiting for %d\n",
 				new_request->requestid);
 			#endif
-			pthread_mutex_unlock(&mutex);
 			goto skip;
 		}
-		rc=pthread_cond_timedwait( 
-			&new_request->condition_cond, 
-			&mutex,&ts);
-		pthread_mutex_unlock(&mutex);
+		pthread_mutex_lock(&new_request->waiting_mutex);
+		if (new_request->done_waiting==0) 
+			rc=pthread_cond_timedwait( 
+				&new_request->waiting_cond, 
+				&new_request->waiting_mutex,&ts);
+		pthread_mutex_unlock(&new_request->waiting_mutex);
+
 		if (rc==ETIMEDOUT) {
 /* FIXME: should handle this case properly */
 			#ifdef DEBUG_DSI
@@ -299,6 +302,7 @@
 			goto out;
 		}
 	} else {
+                /* Don't wait */
 		#ifdef DEBUG_DSI
 		printf("=== Skipping wait altogether for %d\n",new_request->requestid);
 		#endif
@@ -577,6 +581,7 @@
 	unsigned char mins=0;
 	unsigned char checkmessage=0;
 
+	memset(mesg,0,AFP_LOGINMESG_LEN);
 
 	/* The logic here's undocumented.  If we get an attention packet and
 	   there's no flag, then go check the message.  Also, go check the
@@ -862,8 +867,11 @@
 			#ifdef DEBUG_DSI
 			printf("<<< Signalling %d, returning %d or %d\n",request->requestid,request->return_code,rc);
 			#endif
+			pthread_mutex_lock(&request->waiting_mutex);
 			request->wait=0;
-			pthread_cond_signal(&request->condition_cond);
+			request->done_waiting=1;
+			pthread_cond_signal(&request->waiting_cond);
+			pthread_mutex_unlock(&request->waiting_mutex);
 		} else {
 			dsi_remove_from_request_queue(server,request);
 		}
diff -Naur afpfs-ng-0.8.1.orig/lib/forklist.c afpfs-ng-0.8.1/lib/forklist.c
