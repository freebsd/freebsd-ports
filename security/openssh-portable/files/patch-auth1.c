--- auth1.c.orig	Thu Aug 12 14:40:25 2004
+++ auth1.c	Tue Aug 17 05:40:29 2004
@@ -25,6 +25,7 @@
 #include "session.h"
 #include "uidswap.h"
 #include "monitor_wrap.h"
+#include "canohost.h"
 
 /* import */
 extern ServerOptions options;
@@ -69,6 +70,18 @@
 	u_int dlen;
 	u_int ulen;
 	int prev, type = 0;
+#ifdef HAVE_LOGIN_CAP
+	login_cap_t *lc;
+#endif
+#ifdef USE_PAM
+	struct inverted_pam_cookie *pam_cookie;
+#endif /* USE_PAM */
+#if defined(HAVE_LOGIN_CAP) || defined(LOGIN_ACCESS)
+	const char *from_host, *from_ip;
+
+	from_host = get_canonical_hostname(options.use_dns);
+	from_ip = get_remote_ipaddr();
+#endif /* HAVE_LOGIN_CAP || LOGIN_ACCESS */
 
 	debug("Attempting authentication for %s%.100s.",
 	    authctxt->valid ? "" : "invalid user ", authctxt->user);
@@ -217,6 +230,34 @@
 			logit("Unknown message during authentication: type %d", type);
 			break;
 		}
+
+#ifdef HAVE_LOGIN_CAP
+		if (authctxt->pw != NULL) {
+		  lc = login_getpwclass(authctxt->pw);
+		  if (lc == NULL)
+			lc = login_getclassbyname(NULL, authctxt->pw);
+		  if (!auth_hostok(lc, from_host, from_ip)) {
+			logit("Denied connection for %.200s from %.200s [%.200s].",
+		      authctxt->pw->pw_name, from_host, from_ip);
+			packet_disconnect("Sorry, you are not allowed to connect.");
+		  }
+		  if (!auth_timeok(lc, time(NULL))) {
+			logit("LOGIN %.200s REFUSED (TIME) FROM %.200s",
+		      authctxt->pw->pw_name, from_host);
+			packet_disconnect("Logins not available right now.");
+		  }
+		  login_close(lc);
+		  lc = NULL;
+		}
+#endif  /* HAVE_LOGIN_CAP */
+#ifdef LOGIN_ACCESS
+		if (authctxt->pw != NULL && !login_access(authctxt->pw->pw_name, from_host)) {
+		  logit("Denied connection for %.200s from %.200s [%.200s].",
+		      authctxt->pw->pw_name, from_host, from_ip);
+		  packet_disconnect("Sorry, you are not allowed to connect.");
+		}
+#endif /* LOGIN_ACCESS */
+
 #ifdef BSD_AUTH
 		if (authctxt->as) {
 			auth_close(authctxt->as);
