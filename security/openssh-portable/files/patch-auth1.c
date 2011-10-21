--- auth1.c.orig	2010-06-25 18:01:33.000000000 -0600
+++ auth1.c	2010-09-14 16:14:12.000000000 -0600
@@ -40,6 +40,7 @@
 #endif
 #include "monitor_wrap.h"
 #include "buffer.h"
+#include "canohost.h"
 
 /* import */
 extern ServerOptions options;
@@ -239,6 +240,13 @@
 	char info[1024];
 	int prev = 0, type = 0;
 	const struct AuthMethod1 *meth;
+#ifdef HAVE_LOGIN_CAP
+	login_cap_t *lc;
+	const char *from_host, *from_ip;
+
+	from_host = get_canonical_hostname(options.use_dns);
+	from_ip = get_remote_ipaddr();
+#endif
 
 	debug("Attempting authentication for %s%.100s.",
 	    authctxt->valid ? "" : "invalid user ", authctxt->user);
@@ -292,6 +300,26 @@
 			goto skip;
 		}
 
+#ifdef HAVE_LOGIN_CAP
+		if (authctxt->pw != NULL) {
+			lc = login_getpwclass(authctxt->pw);
+			if (lc == NULL)
+				lc = login_getclassbyname(NULL, authctxt->pw);
+			if (!auth_hostok(lc, from_host, from_ip)) {
+				logit("Denied connection for %.200s from %.200s [%.200s].",
+				       authctxt->pw->pw_name, from_host, from_ip);
+				packet_disconnect("Sorry, you are not allowed to connect.");
+			}
+			if (!auth_timeok(lc, time(NULL))) {
+				logit("LOGIN %.200s REFUSED (TIME) FROM %.200s",
+				       authctxt->pw->pw_name, from_host);
+				packet_disconnect("Logins not available right now.");
+			}
+			login_close(lc);
+			lc = NULL;
+		}
+#endif  /* HAVE_LOGIN_CAP */
+
 		if (!*(meth->enabled)) {
 			verbose("%s authentication disabled.", meth->name);
 			goto skip;
