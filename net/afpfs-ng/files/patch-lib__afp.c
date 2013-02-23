--- lib/afp.c.orig	2008-03-08 02:44:16.000000000 +0000
+++ lib/afp.c	2012-10-14 13:13:06.000000000 +0000
@@ -9,7 +9,7 @@
 
 
 
-#include "afp.h"
+#include "afpfs-ng/afp.h"
 #include <config.h>
 
 #include <stdio.h>
@@ -19,19 +19,18 @@
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/socket.h>
-#include <errno.h>
 
-#include "afp_protocol.h"
-#include "libafpclient.h"
+#include "afpfs-ng/afp_protocol.h"
+#include "afpfs-ng/libafpclient.h"
 #include "server.h"
-#include "dsi.h"
+#include "afpfs-ng/dsi.h"
 #include "dsi_protocol.h"
-#include "utils.h"
+#include "afpfs-ng/utils.h"
 #include "afp_replies.h"
 #include "afp_internal.h"
 #include "did.h"
 #include "forklist.h"
-#include "codepage.h"
+#include "afpfs-ng/codepage.h"
 
 struct afp_versions      afp_versions[] = {
             { "AFPVersion 1.1", 11 },
@@ -68,7 +67,7 @@
 	afp_getsessiontoken_reply,afp_blank_reply, NULL, NULL,
 	afp_enumerateext2_reply, NULL, NULL, NULL,    /*64 - 71 */
 	afp_listextattrs_reply, NULL, NULL, NULL,
-	afp_blank_reply, NULL, NULL, NULL,                       /*72 - 79 */
+	afp_blank_reply, NULL, afp_blank_reply, afp_blank_reply,                       /*72 - 79 */
 
 	NULL, NULL, NULL, NULL,
 	NULL, NULL, NULL, NULL,
@@ -320,8 +319,16 @@
 	
 	struct dsi_request * p;
 	struct afp_server *s2;
+
+
+	if (s==NULL) 
+		goto out;
+
 	for (p=s->command_requests;p;p=p->next) {
-		pthread_cond_signal(&p->condition_cond);
+		pthread_mutex_lock(&p->waiting_mutex);
+		p->done_waiting=1;
+		pthread_cond_signal(&p->waiting_cond);
+		pthread_mutex_unlock(&p->waiting_mutex);
 	}
 
 	if (s==server_base) {
@@ -354,7 +361,7 @@
 	s->exit_flag = 0;
 	s->path_encoding=kFPUTF8Name;  /* This is a default */
 	s->next=NULL;
-	s->bufsize=2048;
+	s->bufsize=4096;
 	s->incoming_buffer=malloc(s->bufsize);
 
 	s->attention_quantum=AFP_DEFAULT_ATTENTION_QUANTUM;
@@ -524,13 +531,14 @@
 			kFPVolCreateDateBit|kFPVolIDBit |
 			kFPVolNameBit;
 	char new_encoding;
+     	int ret;
 
 	if (server->using_version->av_number>=30) 
 		bitmap|= kFPVolNameBit|kFPVolBlockSizeBit;
 
-	switch (afp_volopen(volume,bitmap,
-		(strlen(volume->volpassword)>0) ? volume->volpassword : NULL)) 
-	{
+	ret = afp_volopen(volume,bitmap,
+		(strlen(volume->volpassword)>0) ? volume->volpassword : NULL);
+	switch(ret){
 	case kFPAccessDenied:
 		*l+=snprintf(mesg,max-*l,
 			"Incorrect volume password\n");
@@ -544,6 +552,10 @@
 		*l+=snprintf(mesg,max-*l,
 			"Could not open volume\n");
 		goto error;
+	case ETIMEDOUT:
+		*l+=snprintf(mesg,max-*l,
+			"Timed out waiting to open volume\n");
+		goto error;
 	}
 
 	/* It is said that if a volume's encoding will be the same 
@@ -641,7 +653,6 @@
 	add_server(server);
 
 	add_fd_and_signal(server->fd);
-
 	if (!full) {
 		return 0;
 	}
@@ -649,10 +660,13 @@
 	/* Get the status, and calculate the transmit time.  We use this to
 	* calculate our rx quantum. */
 	gettimeofday(&t1,NULL);
+
 	if ((error=dsi_getstatus(server))!=0) 
 		goto error;
 	gettimeofday(&t2,NULL);
 
+        afp_server_identify(server);
+
 	if ((t2.tv_sec - t1.tv_sec) > 0)
 		server->tx_delay= (t2.tv_sec - t1.tv_sec) * 1000;
 	else
diff -Naur afpfs-ng-0.8.1.orig/lib/afp_internal.h afpfs-ng-0.8.1/lib/afp_internal.h
