--- auth1.c.orig	Fri Jun 21 08:21:11 2002
+++ auth1.c	Fri Jun 28 06:57:42 2002
@@ -26,6 +26,7 @@
 #include "session.h"
 #include "uidswap.h"
 #include "monitor_wrap.h"
+#include "canohost.h"
 
 /* import */
 extern ServerOptions options;
@@ -75,6 +76,18 @@
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
@@ -282,6 +295,34 @@
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
