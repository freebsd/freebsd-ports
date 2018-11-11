--- UTC
r99053 | des | 2002-06-29 05:57:13 -0500 (Sat, 29 Jun 2002) | 4 lines
Changed paths:
   M /head/crypto/openssh/auth2.c

Apply class-imposed login restrictions.

--- auth2.c.orig	2018-10-16 17:01:20.000000000 -0700
+++ auth2.c	2018-11-10 11:35:07.816193000 -0800
@@ -48,6 +48,7 @@
 #include "sshkey.h"
 #include "hostfile.h"
 #include "auth.h"
+#include "canohost.h"
 #include "dispatch.h"
 #include "pathnames.h"
 #include "sshbuf.h"
@@ -258,7 +259,14 @@ input_userauth_request(int type, u_int32_t seq, struct
 	char *user, *service, *method, *style = NULL;
 	int authenticated = 0;
 	double tstart = monotime_double();
+#ifdef HAVE_LOGIN_CAP
+	login_cap_t *lc;
+	const char *from_host, *from_ip;
 
+	from_host = auth_get_canonical_hostname(ssh, options.use_dns);
+	from_ip = ssh_remote_ipaddr(ssh);
+#endif
+
 	if (authctxt == NULL)
 		fatal("input_userauth_request: no authctxt");
 
@@ -307,6 +315,27 @@ input_userauth_request(int type, u_int32_t seq, struct
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
 	auth2_challenge_stop(ssh);
 
