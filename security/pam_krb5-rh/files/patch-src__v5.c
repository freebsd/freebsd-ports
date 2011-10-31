--- ./src/v5.c.orig	2011-07-29 15:31:01.000000000 -0400
+++ ./src/v5.c	2011-10-24 09:25:15.000000000 -0400
@@ -1350,6 +1350,9 @@
 	krb5_creds tmpcreds;
 	krb5_ccache ccache;
 	krb5_get_init_creds_opt *tmp_gicopts;
+	krb5_timestamp sec;
+	const char *e = NULL;
+	char *p;
 
 	/* In case we already have creds, get rid of them. */
 	krb5_free_cred_contents(ctx, creds);
@@ -1393,23 +1396,50 @@
 		memset(&service_principal, 0, sizeof(service_principal));
 		if (krb5_parse_name(ctx, realm_service,
 				    &service_principal) == 0) {
-			if (options->debug) {
-				debug("attempting to read existing credentials "
-				      "from %s", krb5_cc_default_name(ctx));
-			}
 			memset(&ccache, 0, sizeof(ccache));
 			/* In case we're setuid/setgid, switch to the caller's
 			 * permissions. */
 			saved_perms = _pam_krb5_switch_perms();
+
+			e = getenv("KRB5CCNAME");
+			if (e) {
+	        		p = strndup(e, 128);
+	        		if (p == NULL) {
+					memset(&e, 0, sizeof(e));
+					if (options->debug)
+		        			debug("malloc: out of memory");
+					return ENOMEM;
+	        		}
+	        		if ((strnlen(p, 128) > 96) || strnlen(p, 128) <= 0) {
+					memset(&e, 0, sizeof(e));
+					if (options->debug)
+		        			debug("KRB5CCNAME is too long or too short, aborting");
+					return PAM_SYSTEM_ERR;
+	        		}
+	        		if (strncmp(p, "FILE", 4) == 0 && (p[4] == ':' || p[4] == '='))
+					krb5_cc_set_default_name(ctx, p);
+	        		else {
+					if (options->debug)
+		        			debug("KRB5CCNAME does not start with FILE:");
+	        		}
+	        		memset(&e, 0, sizeof(e));
+			}
+			if (options->debug) {
+				debug("attempting to read existing credentials "
+					"from %s", krb5_cc_default_name(ctx));
+			}
 			if ((saved_perms != NULL) &&
 			    (krb5_cc_default(ctx, &ccache) == 0)) {
+				krb5_timeofday (ctx, &sec);
 				tmpcreds.client = userinfo->principal_name;
 				tmpcreds.server = service_principal;
 				i = krb5_cc_retrieve_cred(ctx, ccache, 0,
 							  &tmpcreds, creds);
-				/* FIXME: check if the creds are expired?
-				 * What's the right error code if we check, and
-				 * they are? */
+				if ((i == 0) && creds->times.endtime < sec) {
+					if (options->debug)
+						warn("Credentials expired");
+					i = KRB5_KPASSWD_AUTHERROR;
+				}
 				memset(&tmpcreds, 0, sizeof(tmpcreds));
 				krb5_cc_close(ctx, ccache);
 				/* In case we're setuid/setgid, restore the
