--- auth2.c.orig	Fri May 31 13:35:15 2002
+++ auth2.c	Fri Jun 28 06:45:47 2002
@@ -35,6 +35,7 @@
 #include "dispatch.h"
 #include "pathnames.h"
 #include "monitor_wrap.h"
+#include "canohost.h"
 
 /* import */
 extern ServerOptions options;
@@ -133,6 +134,15 @@
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
@@ -152,8 +162,14 @@
 		if (authctxt->pw && strcmp(service, "ssh-connection")==0) {
 			authctxt->valid = 1;
 			debug2("input_userauth_request: setting up authctxt for %s", user);
+
+#ifdef USE_PAM
+			start_pam(authctxt->pw);
+#endif
+
 		} else {
 			log("input_userauth_request: illegal user %s", user);
+			authctxt->pw = NULL;
 		}
 		setproctitle("%s%s", authctxt->pw ? user : "unknown",
 		    use_privsep ? " [net]" : "");
@@ -168,6 +184,41 @@
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
@@ -178,6 +229,12 @@
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
