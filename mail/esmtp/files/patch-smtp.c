
$FreeBSD$

--- smtp.c.orig	Fri Nov  7 12:47:16 2003
+++ smtp.c	Tue Jun 29 15:27:29 2004
@@ -426,9 +426,14 @@
 		goto failure;
 
 	/* Do what's needed at application level to use authentication. */
-	authctx = auth_create_context ();
-	auth_set_mechanism_flags (authctx, AUTH_PLUGIN_PLAIN, 0);
-	auth_set_interact_cb (authctx, authinteract, identity);
+	if(identity->user || identity->pass)
+	{
+		authctx = auth_create_context ();
+		auth_set_mechanism_flags (authctx, AUTH_PLUGIN_PLAIN, 0);
+		auth_set_interact_cb (authctx, authinteract, identity);
+	}
+	else
+		authctx = NULL;
 
 	/* Use our callback for X.509 certificate passwords.  If STARTTLS is not in
 	 * use or disabled in configure, the following is harmless.
@@ -560,7 +565,8 @@
 		fputc('\n', log_fp);
 
 	smtp_destroy_session (session);
-	auth_destroy_context (authctx);
+	if(authctx)
+		auth_destroy_context (authctx);
 	auth_client_exit ();
 
 	return;
