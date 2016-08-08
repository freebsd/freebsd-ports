--- UTC
r99053 | des | 2002-06-29 05:57:13 -0500 (Sat, 29 Jun 2002) | 4 lines
Changed paths:
   M /head/crypto/openssh/auth2.c

Apply class-imposed login restrictions.

--- auth2.c.orig	2012-12-02 16:53:20.000000000 -0600
+++ auth2.c	2013-05-22 17:21:37.979631466 -0500
@@ -46,6 +46,7 @@
 #include "key.h"
 #include "hostfile.h"
 #include "auth.h"
+#include "canohost.h"
 #include "dispatch.h"
 #include "pathnames.h"
 #include "buffer.h"
@@ -216,6 +217,14 @@ input_userauth_request(int type, u_int32
 	Authmethod *m = NULL;
 	char *user, *service, *method, *style = NULL;
 	int authenticated = 0;
+#ifdef HAVE_LOGIN_CAP
+	struct ssh *ssh = active_state; /* XXX */
+	login_cap_t *lc;
+	const char *from_host, *from_ip;
+
+	from_host = auth_get_canonical_hostname(ssh, options.use_dns);
+	from_ip = ssh_remote_ipaddr(ssh);
+#endif
 
 	if (authctxt == NULL)
 		fatal("input_userauth_request: no authctxt");
@@ -262,6 +271,27 @@ input_userauth_request(int type, u_int32
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
+			logit("Denied connection for %.200s from %.200s [%.200s].",
+			    authctxt->pw->pw_name, from_host, from_ip);
+			packet_disconnect("Sorry, you are not allowed to connect.");
+		}
+		if (!auth_timeok(lc, time(NULL))) {
+			logit("LOGIN %.200s REFUSED (TIME) FROM %.200s",
+			    authctxt->pw->pw_name, from_host);
+			packet_disconnect("Logins not available right now.");
+		}
+		login_close(lc);
+		lc = NULL;
+	}
+#endif  /* HAVE_LOGIN_CAP */
+
 	/* reset state */
 	auth2_challenge_stop(authctxt);
 
