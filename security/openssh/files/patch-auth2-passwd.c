--- auth2-passwd.c.orig	Fri May 31 13:35:15 2002
+++ auth2-passwd.c	Fri Jun 21 22:54:05 2002
@@ -48,7 +48,11 @@
 	password = packet_get_string(&len);
 	packet_check_eom();
 	if (authctxt->valid &&
+#ifdef USE_PAM
+	    PRIVSEP(auth_pam_password(authctxt, password)) == 1)
+#else
 	    PRIVSEP(auth_password(authctxt, password)) == 1)
+#endif
 		authenticated = 1;
 	memset(password, 0, len);
 	xfree(password);
