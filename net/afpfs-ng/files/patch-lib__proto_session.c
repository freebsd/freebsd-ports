--- lib/proto_session.c.orig	2008-02-18 03:46:19.000000000 +0000
+++ lib/proto_session.c	2012-10-14 13:11:44.000000000 +0000
@@ -8,10 +8,10 @@
  */
 #include <stdlib.h>
 #include <string.h>
-#include "dsi.h"
+#include "afpfs-ng/dsi.h"
 #include "dsi_protocol.h"
-#include "afp.h"
-#include "utils.h"
+#include "afpfs-ng/afp.h"
+#include "afpfs-ng/utils.h"
 
 int afp_getsessiontoken(struct afp_server * server, int type, 
 	unsigned int timestamp, struct afp_token *outgoing_token, 
@@ -39,7 +39,7 @@
 	switch (type) {
 	case kLoginWithTimeAndID:
 	case kReconnWithTimeAndID: {
-		uint32_t *p = (void *) (((unsigned int) request)+
+		uint32_t *p = (void *) (((unsigned long) request)+
 			sizeof(*request));
 
 		offset=sizeof(timestamp);
@@ -63,7 +63,7 @@
 		goto error;
 	}
 
-	data=(void *) (((unsigned int) request)+sizeof(*request)+offset);
+	data=(void *) (((unsigned long) request)+sizeof(*request)+offset);
 	request->idlength=htonl(datalen);
 	request->pad=0;
 	request->type=htons(type);
@@ -127,7 +127,7 @@
 	if ((request=malloc(sizeof(*request) + AFP_TOKEN_MAX_LEN))==NULL)
 		return -1;
 
-	token_data  = request + sizeof(*request);
+	token_data  = (char *)request + sizeof(*request);
 
 	request->type=htons(type);
 
diff -Naur afpfs-ng-0.8.1.orig/lib/proto_volume.c afpfs-ng-0.8.1/lib/proto_volume.c
