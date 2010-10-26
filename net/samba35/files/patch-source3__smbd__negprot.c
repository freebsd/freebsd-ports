--- ./source3/smbd/negprot.c.orig	2010-10-26 02:46:36.000000000 +0200
+++ ./source3/smbd/negprot.c	2010-10-26 02:53:28.000000000 +0200
@@ -28,27 +28,25 @@
 {
 	NTSTATUS nt_status;
 	struct smbd_server_connection *sconn = smbd_server_conn;
+	struct auth_context *actx = sconn->smb1.negprot.auth_context;
 
 	/* We might be called more than once, multiple negprots are
 	 * permitted */
-	if (sconn->smb1.negprot.auth_context) {
+	if (actx) {
 		DEBUG(3, ("get challenge: is this a secondary negprot? "
 			  "sconn->negprot.auth_context is non-NULL!\n"));
-			sconn->smb1.negprot.auth_context->free(
-				&sconn->smb1.negprot.auth_context);
+			(actx->free)(&actx);
 	}
 
 	DEBUG(10, ("get challenge: creating negprot_global_auth_context\n"));
-	nt_status = make_auth_context_subsystem(
-		&sconn->smb1.negprot.auth_context);
+	nt_status = make_auth_context_subsystem(&actx);
 	if (!NT_STATUS_IS_OK(nt_status)) {
 		DEBUG(0, ("make_auth_context_subsystem returned %s",
 			  nt_errstr(nt_status)));
 		smb_panic("cannot make_negprot_global_auth_context!");
 	}
 	DEBUG(10, ("get challenge: getting challenge\n"));
-	sconn->smb1.negprot.auth_context->get_ntlm_challenge(
-		sconn->smb1.negprot.auth_context, buff);
+	actx->get_ntlm_challenge(actx, buff);
 }
 
 /****************************************************************************
