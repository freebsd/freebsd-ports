--- auth2.c.orig	Mon May 13 04:37:39 2002
+++ auth2.c	Thu May 23 13:11:43 2002
@@ -168,6 +168,15 @@
 	Authmethod *m = NULL;
 	char *user, *service, *method, *style = NULL;
 	int authenticated = 0;
+#ifdef HAVE_LOGIN_CAP
+	login_cap_t *lc;
+#endif /* HAVE_LOGIN_CAP */
+#if defined(HAVE_LOGIN_CAP) || defined(LOGIN_ACCESS)
+	const char *from_host, *from_ip;
+
+	from_host = get_canonical_hostname(options.verify_reverse_mapping);
+	from_ip = get_remote_ipaddr();
+#endif /* HAVE_LOGIN_CAP || LOGIN_ACCESS */
 
 	if (authctxt == NULL)
 		fatal("input_userauth_request: no authctxt");
@@ -187,6 +196,11 @@
 		if (authctxt->pw && strcmp(service, "ssh-connection")==0) {
 			authctxt->valid = 1;
 			debug2("input_userauth_request: setting up authctxt for %s", user);
+
+#ifdef USE_PAM
+			start_pam(pw);
+#endif
+
 		} else {
 			log("input_userauth_request: illegal user %s", user);
 		}
@@ -203,6 +217,41 @@
 		    "(%s,%s) -> (%s,%s)",
 		    authctxt->user, authctxt->service, user, service);
 	}
+
+#ifdef HAVE_LOGIN_CAP
+	if (authctxt->pw != NULL) {
+		lc = login_getpwclass(authctxt->pw);
+		if (lc == NULL)
+			lc = login_getclassbyname(NULL, authctxt->pw);
+		if (!auth_hostok(lc, from_host, from_ip)) {
+			log("Denied connection for %.200s from %.200s [%.200s].",
+			    authctxt->pw->pw_name, from_host, from_ip);
+			packet_disconnect("Sorry, you are not allowed to connect.");
+		}
+		if (!auth_timeok(lc, time(NULL))) {
+			log("LOGIN %.200s REFUSED (TIME) FROM %.200s",
+			    authctxt->pw->pw_name, from_host);
+			packet_disconnect("Logins not available right now.");
+		}
+		login_close(lc);
+		lc = NULL;
+	}
+#endif  /* HAVE_LOGIN_CAP */
+#ifdef LOGIN_ACCESS
+	if (authctxt->pw != NULL &&
+	    !login_access(authctxt->pw->pw_name, from_host)) {
+		log("Denied connection for %.200s from %.200s [%.200s].",
+		    authctxt->pw->pw_name, from_host, from_ip);
+		packet_disconnect("Sorry, you are not allowed to connect.");
+	}
+#endif /* LOGIN_ACCESS */
+#ifdef BSD_AUTH
+	if (authctxt->as) {
+		auth_close(authctxt->as);
+		authctxt->as = NULL;
+	}
+#endif
+
 	/* reset state */
 	auth2_challenge_stop(authctxt);
 	authctxt->postponed = 0;
@@ -213,6 +262,12 @@
 		debug2("input_userauth_request: try method %s", method);
 		authenticated =	m->userauth(authctxt);
 	}
+
+#ifdef USE_PAM
+	if (authenticated && authctxt->user && !do_pam_account(authctxt->user, NULL))
+		authenticated = 0;
+#endif /* USE_PAM */
+
 	userauth_finish(authctxt, authenticated, method);
 
 	xfree(service);
@@ -321,7 +376,11 @@
 		m->enabled = NULL;
 	packet_check_eom();
 	userauth_banner();
+#ifdef USE_PAM
+	return (authctxt->valid ? PRIVSEP(auth_pam_password(authctxt, "")) : 0);
+#else
 	return (authctxt->valid ? PRIVSEP(auth_password(authctxt, "")) : 0);
+#endif
 }
 
 static int
