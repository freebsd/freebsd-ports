--- auth1.c.orig	Tue Feb  8 11:52:48 2005
+++ auth1.c	Sat Mar 19 21:34:47 2005
@@ -26,6 +26,7 @@
 #include "uidswap.h"
 #include "monitor_wrap.h"
 #include "buffer.h"
+#include "canohost.h"
 
 /* import */
 extern ServerOptions options;
@@ -71,6 +72,15 @@
 	u_int dlen;
 	u_int ulen;
 	int prev, type = 0;
+#ifdef HAVE_LOGIN_CAP
+	login_cap_t *lc;
+#endif /* HAVE_LOGIN_CAP */
+#if defined(HAVE_LOGIN_CAP) || defined(LOGIN_ACCESS)
+	const char *from_host, *from_ip;
+
+	from_host = get_canonical_hostname(options.use_dns);
+	from_ip = get_remote_ipaddr();
+#endif /* HAVE_LOGIN_CAP || LOGIN_ACCESS */
 
 	debug("Attempting authentication for %s%.100s.",
 	    authctxt->valid ? "" : "invalid user ", authctxt->user);
@@ -219,6 +229,34 @@
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
