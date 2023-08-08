--- lib/krb5/recvauth.c.orig	2022-09-15 16:54:19.000000000 -0700
+++ lib/krb5/recvauth.c	2022-11-21 14:37:31.130429000 -0800
@@ -98,7 +98,7 @@
     const char *version = KRB5_SENDAUTH_VERSION;
     char her_version[sizeof(KRB5_SENDAUTH_VERSION)];
     char *her_appl_version;
-    uint32_t len;
+    uint32_t len, bytes;
     u_char repl;
     krb5_data data;
     krb5_flags ap_options;
@@ -166,15 +166,21 @@
 	krb5_net_write (context, p_fd, &repl, 1);
 	return krb5_enomem(context);
     }
-    if (krb5_net_read (context, p_fd, her_appl_version, len) != len
-	|| !(*match_appl_version)(match_data, her_appl_version)) {
-	repl = 2;
-	krb5_net_write (context, p_fd, &repl, 1);
-	krb5_set_error_message(context, KRB5_SENDAUTH_BADAPPLVERS,
-			       N_("wrong sendauth application version (%s)", ""),
-			       her_appl_version);
-	free (her_appl_version);
-	return KRB5_SENDAUTH_BADAPPLVERS;
+    if ((bytes = krb5_net_read (context, p_fd, her_appl_version, len))) {
+	/* PR/267884: String read must always conatain a terminating NUL */
+	if (strnlen(her_appl_version, len) == len)
+		her_appl_version[len-1] = '\0';
+
+	if (bytes != len ||
+		!(*match_appl_version)(match_data, her_appl_version)) {
+		repl = 2;
+		krb5_net_write (context, p_fd, &repl, 1);
+		krb5_set_error_message(context, KRB5_SENDAUTH_BADAPPLVERS,
+				       N_("wrong sendauth application version (%s)", ""),
+				       her_appl_version);
+		free (her_appl_version);
+		return KRB5_SENDAUTH_BADAPPLVERS;
+    	}
     }
     free (her_appl_version);
 
