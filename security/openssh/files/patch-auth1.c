--- auth1.c.orig	Sun Feb  3 18:53:25 2002
+++ auth1.c	Sun Mar 17 20:14:40 2002
@@ -75,6 +75,18 @@
 	u_int ulen;
 	int type = 0;
 	struct passwd *pw = authctxt->pw;
+#ifdef HAVE_LOGIN_CAP
+	login_cap_t *lc;
+#endif
+#ifdef USE_PAM
+	struct inverted_pam_cookie *pam_cookie;
+#endif /* USE_PAM */
+#if defined(HAVE_LOGIN_CAP) || defined(LOGIN_ACCESS)
+	const char *from_host, *from_ip;
+
+	from_host = get_canonical_hostname(options.verify_reverse_mapping);
+	from_ip = get_remote_ipaddr();
+#endif /* HAVE_LOGIN_CAP || LOGIN_ACCESS */
 
 	debug("Attempting authentication for %s%.100s.",
 	    authctxt->valid ? "" : "illegal user ", authctxt->user);
@@ -84,7 +96,11 @@
 #if defined(KRB4) || defined(KRB5)
 	    (!options.kerberos_authentication || options.kerberos_or_local_passwd) &&
 #endif
+#ifdef USE_PAM
+	    auth_pam_password(authctxt, "")
+#else
 	    auth_password(authctxt, "")) {
+#endif
 		auth_log(authctxt, 1, "without authentication", "");
 		return;
 	}
@@ -94,6 +110,8 @@
 	packet_send();
 	packet_write_wait();
 
+	client_user = NULL;
+
 	for (;;) {
 		/* default to fail */
 		authenticated = 0;
@@ -284,6 +302,34 @@
 			log("Unknown message during authentication: type %d", type);
 			break;
 		}
+
+#ifdef HAVE_LOGIN_CAP
+		if (pw != NULL) {
+		  lc = login_getpwclass(pw);
+		  if (lc == NULL)
+			lc = login_getclassbyname(NULL, pw);
+		  if (!auth_hostok(lc, from_host, from_ip)) {
+			log("Denied connection for %.200s from %.200s [%.200s].",
+		      pw->pw_name, from_host, from_ip);
+			packet_disconnect("Sorry, you are not allowed to connect.");
+		  }
+		  if (!auth_timeok(lc, time(NULL))) {
+			log("LOGIN %.200s REFUSED (TIME) FROM %.200s",
+		      pw->pw_name, from_host);
+			packet_disconnect("Logins not available right now.");
+		  }
+		  login_close(lc);
+		  lc = NULL;
+		}
+#endif  /* HAVE_LOGIN_CAP */
+#ifdef LOGIN_ACCESS
+		if (pw != NULL && !login_access(pw->pw_name, from_host)) {
+		  log("Denied connection for %.200s from %.200s [%.200s].",
+		      pw->pw_name, from_host, from_ip);
+		  packet_disconnect("Sorry, you are not allowed to connect.");
+		}
+#endif /* LOGIN_ACCESS */
+
 #ifdef BSD_AUTH
 		if (authctxt->as) {
 			auth_close(authctxt->as);
@@ -302,6 +348,15 @@
 		/* Log before sending the reply */
 		auth_log(authctxt, authenticated, get_authname(type), info);
 
+#ifdef USE_PAM
+		if (authenticated && !do_pam_account(pw->pw_name, client_user))
+			authenticated = 0;
+#endif
+		if (client_user != NULL) {
+			xfree(client_user);
+			client_user = NULL;
+		}
+
 		if (authenticated)
 			return;
 
@@ -354,6 +409,11 @@
 		pw = NULL;
 	}
 	authctxt->pw = pw;
+
+#ifdef USE_PAM
+	if (pw != NULL)
+		start_pam(pw);
+#endif
 
 	setproctitle("%s", pw ? user : "unknown");
 
