--- auth2.c.orig	2009-06-22 00:11:07.000000000 -0600
+++ auth2.c	2010-09-14 16:14:12.000000000 -0600
@@ -46,6 +46,7 @@
 #include "key.h"
 #include "hostfile.h"
 #include "auth.h"
+#include "canohost.h"
 #include "dispatch.h"
 #include "pathnames.h"
 #include "buffer.h"
@@ -217,6 +218,13 @@
 	Authmethod *m = NULL;
 	char *user, *service, *method, *style = NULL;
 	int authenticated = 0;
+#ifdef HAVE_LOGIN_CAP
+	login_cap_t *lc;
+	const char *from_host, *from_ip;
+
+	from_host = get_canonical_hostname(options.use_dns);
+	from_ip = get_remote_ipaddr();
+#endif
 
 	if (authctxt == NULL)
 		fatal("input_userauth_request: no authctxt");
@@ -261,6 +269,27 @@
 		    "(%s,%s) -> (%s,%s)",
 		    authctxt->user, authctxt->service, user, service);
 	}
+
+#ifdef HAVE_LOGIN_CAP
+        if (authctxt->pw != NULL) {
+                lc = login_getpwclass(authctxt->pw);
+                if (lc == NULL)
+                        lc = login_getclassbyname(NULL, authctxt->pw);
+                if (!auth_hostok(lc, from_host, from_ip)) {
+                        logit("Denied connection for %.200s from %.200s [%.200s].",
+                            authctxt->pw->pw_name, from_host, from_ip);
+                        packet_disconnect("Sorry, you are not allowed to connect.");
+                }
+                if (!auth_timeok(lc, time(NULL))) {
+                        logit("LOGIN %.200s REFUSED (TIME) FROM %.200s",
+                            authctxt->pw->pw_name, from_host);
+                        packet_disconnect("Logins not available right now.");
+                }
+                login_close(lc);
+                lc = NULL;
+        }
+#endif  /* HAVE_LOGIN_CAP */
+
 	/* reset state */
 	auth2_challenge_stop(authctxt);
 #ifdef JPAKE
