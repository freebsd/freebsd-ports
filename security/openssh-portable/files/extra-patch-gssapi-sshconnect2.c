Avoid free(const char*)
--- sshconnect2.c.orig	2020-11-19 14:56:54.387846000 -0800
+++ sshconnect2.c	2020-11-19 14:57:04.445045000 -0800
@@ -846,7 +846,7 @@ userauth_gssapi(struct ssh *ssh)
 		/* Fall back to specified host if we are using proxy command
 		 * and can not use DNS on that socket */
 		if (strcmp(gss_host, "UNKNOWN") == 0) {
-			gss_host = authctxt->host;
+			gss_host = xstrdup(authctxt->host);
 		}
 	} else {
 		gss_host = xstrdup(authctxt->host);
