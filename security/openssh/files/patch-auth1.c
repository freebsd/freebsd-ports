--- auth1.c.orig	Wed Jun 19 02:27:55 2002
+++ auth1.c	Sun Jul  7 20:36:36 2002
@@ -26,6 +26,15 @@
 #include "session.h"
 #include "uidswap.h"
 #include "monitor_wrap.h"
+#include "canohost.h"
+
+#ifdef HAVE_LOGIN_CAP
+#include <login_cap.h>
+#endif /* HAVE_LOGIN_CAP */
+#ifdef USE_PAM
+#include "auth-pam.h"
+#include <security/pam_appl.h>
+#endif /* USE_PAM */
 
 /* import */
 extern ServerOptions options;
@@ -75,6 +84,16 @@
 	u_int ulen;
 	int type = 0;
 	struct passwd *pw = authctxt->pw;
+#ifdef HAVE_LOGIN_CAP
+	login_cap_t *lc;
+#endif /* HAVE_LOGIN_CAP */
+#ifdef USE_PAM
+	struct inverted_pam_cookie *pam_cookie;
+#endif /* USE_PAM */
+	const char *from_host, *from_ip;
+
+	from_host = get_canonical_hostname(options.verify_reverse_mapping);
+	from_ip = get_remote_ipaddr();
 
 	debug("Attempting authentication for %s%.100s.",
 	    authctxt->valid ? "" : "illegal user ", authctxt->user);
@@ -84,7 +103,11 @@
 #if defined(KRB4) || defined(KRB5)
 	    (!options.kerberos_authentication || options.kerberos_or_local_passwd) &&
 #endif
-	    PRIVSEP(auth_password(authctxt, ""))) {
+#ifdef USE_PAM
+	   PRIVSEP(auth_pam_password(authctxt, ""))) {
+#else
+	   PRIVSEP(auth_password(authctxt, ""))) {
+#endif /* USE_PAM */
 		auth_log(authctxt, 1, "without authentication", "");
 		return;
 	}
@@ -94,6 +117,8 @@
 	packet_send();
 	packet_write_wait();
 
+	client_user = NULL;
+
 	for (;;) {
 		/* default to fail */
 		authenticated = 0;
@@ -243,12 +268,52 @@
 			packet_check_eom();
 
 			/* Try authentication with the password. */
-			authenticated = PRIVSEP(auth_password(authctxt, password));
+			authenticated =
+#ifdef USE_PAM
+				PRIVSEP(auth_pam_password(authctxt, password));
+#else
+				PRIVSEP(auth_password(authctxt, password));
+#endif /* USE_PAM */
 
 			memset(password, 0, strlen(password));
 			xfree(password);
 			break;
 
+#ifdef USE_PAM
+		case SSH_CMSG_AUTH_TIS:
+			debug("rcvd SSH_CMSG_AUTH_TIS: Trying PAM");
+			if (pw == NULL)
+				break;
+			pam_cookie = ipam_start_auth("sshd", pw->pw_name);
+			if (pam_cookie == NULL)
+				break;
+			/* We now have data available to send as a challenge */
+			if (pam_cookie->num_msg != 1 ||
+			    (pam_cookie->msg[0]->msg_style != PAM_PROMPT_ECHO_OFF &&
+			     pam_cookie->msg[0]->msg_style != PAM_PROMPT_ECHO_ON)) {
+			    /* We got several challenges or an unknown challenge type */
+			    ipam_free_cookie(pam_cookie);
+			    pam_cookie = NULL;
+			    break;
+			}
+			packet_start(SSH_SMSG_AUTH_TIS_CHALLENGE);
+			packet_put_string(pam_cookie->msg[0]->msg, strlen(pam_cookie->msg[0]->msg));
+			packet_send();
+			packet_write_wait();
+			continue;
+		case SSH_CMSG_AUTH_TIS_RESPONSE:
+			debug("rcvd SSH_CMSG_AUTH_TIS_RESPONSE");
+			if (pam_cookie != NULL) {
+			    char *response = packet_get_string(&dlen);
+			    
+			    pam_cookie->resp[0]->resp = strdup(response);
+			    xfree(response);
+			    authenticated = ipam_complete_auth(pam_cookie);
+			    ipam_free_cookie(pam_cookie);
+			    pam_cookie = NULL;
+			}
+			break;
+#elif defined(SKEY)
 		case SSH_CMSG_AUTH_TIS:
 			debug("rcvd SSH_CMSG_AUTH_TIS");
 			if (options.challenge_response_authentication == 1) {
@@ -275,6 +340,12 @@
 				xfree(response);
 			}
 			break;
+#else
+		case SSH_CMSG_AUTH_TIS:
+			/* TIS Authentication is unsupported */
+			log("TIS authentication unsupported.");
+			break;
+#endif
 
 		default:
 			/*
@@ -284,6 +355,34 @@
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
@@ -299,9 +398,23 @@
 		    !auth_root_allowed(get_authname(type)))
 			authenticated = 0;
 
+		if (pw != NULL && pw->pw_uid == 0)
+		  log("ROOT LOGIN as '%.100s' from %.100s",
+		      pw->pw_name, from_host);
+
 		/* Log before sending the reply */
 		auth_log(authctxt, authenticated, get_authname(type), info);
 
+#ifdef USE_PAM
+		if (authenticated && !do_pam_account(pw->pw_name, client_user))
+			authenticated = 0;
+#endif
+
+		if (client_user != NULL) {
+			xfree(client_user);
+			client_user = NULL;
+		}
+
 		if (authenticated)
 			return;
 
@@ -354,6 +467,11 @@
 		authctxt->valid = 1;
 	else
 		debug("do_authentication: illegal user %s", user);
+
+#ifdef USE_PAM
+	if (authctxt->pw != NULL)
+		start_pam(authctxt->pw);
+#endif
 
 	setproctitle("%s%s", authctxt->pw ? user : "unknown",
 	    use_privsep ? " [net]" : "");
