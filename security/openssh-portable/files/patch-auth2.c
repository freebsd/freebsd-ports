--- UTC
r99053 | des | 2002-06-29 05:57:13 -0500 (Sat, 29 Jun 2002) | 4 lines
Changed paths:
   M /head/crypto/openssh/auth2.c

Apply class-imposed login restrictions.

--- auth2.c.orig	2020-09-27 00:25:01.000000000 -0700
+++ auth2.c	2020-11-16 13:55:25.222771000 -0800
@@ -266,6 +266,10 @@ input_userauth_request(int type, u_int32_t seq, struct
 	char *user = NULL, *service = NULL, *method = NULL, *style = NULL;
 	int r, authenticated = 0;
 	double tstart = monotime_double();
+#ifdef HAVE_LOGIN_CAP
+	login_cap_t *lc;
+	const char *from_host, *from_ip;
+#endif
 
 	if (authctxt == NULL)
 		fatal("input_userauth_request: no authctxt");
@@ -317,6 +321,26 @@ input_userauth_request(int type, u_int32_t seq, struct
 		    "not allowed: (%s,%s) -> (%s,%s)",
 		    authctxt->user, authctxt->service, user, service);
 	}
+
+#ifdef HAVE_LOGIN_CAP
+	if (authctxt->pw != NULL &&
+	    (lc = login_getpwclass(authctxt->pw)) != NULL) {
+		from_host = auth_get_canonical_hostname(ssh, options.use_dns);
+		from_ip = ssh_remote_ipaddr(ssh);
+		if (!auth_hostok(lc, from_host, from_ip)) {
+			logit("Denied connection for %.200s from %.200s [%.200s].",
+			    authctxt->pw->pw_name, from_host, from_ip);
+			ssh_packet_disconnect(ssh, "Sorry, you are not allowed to connect.");
+		}
+		if (!auth_timeok(lc, time(NULL))) {
+			logit("LOGIN %.200s REFUSED (TIME) FROM %.200s",
+			    authctxt->pw->pw_name, from_host);
+			ssh_packet_disconnect(ssh, "Logins not available right now.");
+		}
+		login_close(lc);
+	}
+#endif  /* HAVE_LOGIN_CAP */
+
 	/* reset state */
 	auth2_challenge_stop(ssh);
 
