--- ./src/modules/rlm_krb5/rlm_krb5.c.orig	2011-09-30 10:12:07.000000000 -0400
+++ ./src/modules/rlm_krb5/rlm_krb5.c	2012-01-29 12:06:04.000000000 -0500
@@ -322,16 +322,41 @@
 #else /* HEIMDAL_KRB5 */
 
 /* validate user/pass, heimdal krb5 way */
-static int krb5_auth(void *instance, REQUEST *request)
+static int krb5_auth(rlm_krb5_t *instance, REQUEST *request)
 {
 	int r;
-	krb5_error_code ret;
+	krb5_error_code ret, ret2;
 	krb5_ccache id;
 	krb5_principal userP;
 
 	krb5_context context = *((rlm_krb5_t *)instance)->context; /* copy data */
 	const char *user, *pass;
 
+	/* arbitrary 64-byte limit on service names; I've never seen a
+	   service name this long, and hope never to. -srl */
+	/* stolen from the above mit kerb stuff -- kula */
+
+	char service[64] = "host";
+	char *servername = NULL;
+	char *princ_name;
+
+	krb5_verify_opt krb_verify_options;
+	krb5_keytab keytab;
+
+	if (instance->service_princ != NULL) {
+		servername = strchr(instance->service_princ, '/');
+		if (servername != NULL) {
+			*servername = '\0';
+		}
+
+		strncpy(service,instance->service_princ,sizeof(service));
+		service[sizeof(service)-1] = '\0';
+		if (servername != NULL) {
+			*servername = '/';
+			servername++;
+		}
+	}
+
 	/*
 	 *	We can only authenticate user requests which HAVE
 	 *	a User-Name attribute.
@@ -374,26 +399,70 @@
 	/*
 	 * Heimdal krb5 verification
 	 */
-	radlog(L_AUTH, "rlm_krb5: Parsed name is: %s@%s\n",
-	       *userP->name.name_string.val,
-	       userP->realm);
+
+
+	/*
+	 *  The following bit allows us to also log user/instance@REALM if someone
+	 *  logs in using an instance
+	 */
+
+	ret = krb5_unparse_name(context, userP, &princ_name);
+	if ( ret != 0 ) {
+		radlog(L_AUTH, "rlm_krb5: krb5_unparse_name unparsable name\n");
+	} else {
+		radlog(L_AUTH, "rlm_krb5: Parsed name is: %s\n", princ_name);
+		free(princ_name);
+	}
 
 	krb5_cc_default(context, &id);
 
-	ret = krb5_verify_user(context,
-			       userP,
-			       id,
-			       pass, 1, "radius");
+        /* Set up krb5_verify_user options */
+        krb5_verify_opt_init(&krb_verify_options);
 
-       if (ret == 0)
-	 return RLM_MODULE_OK;
+        krb5_verify_opt_set_ccache(&krb_verify_options, id);
 
-       radlog(L_AUTH, "rlm_krb5: failed verify_user: %s (%s@%s )",
-	      error_message(ret),
-	      *userP->name.name_string.val,
-	      userP->realm);
+        /*
+	 *  Resolve keytab name. This allows us to use something other than
+	 *  the default system keytab
+	 */
 
-       return RLM_MODULE_REJECT;
+	if (instance->keytab != NULL)
+	{
+		ret = krb5_kt_resolve(context, instance->keytab, &keytab);
+
+		if ( ret )
+		{
+			radlog(L_AUTH, "rlm_krb: unable to resolve keytab %s: %s",
+			       instance->keytab, error_message(ret));
+			krb5_kt_close(context, keytab);
+			return RLM_MODULE_REJECT;
+		}
+		krb5_verify_opt_set_keytab(&krb_verify_options, keytab);
+	}
+
+	/* Verify aquired credentials against the keytab */
+
+	krb5_verify_opt_set_secure(&krb_verify_options, 1);
+
+	/* Allow us to use an arbitrary service name */
+
+        krb5_verify_opt_set_service(&krb_verify_options, service);
+
+	/* Verify the user, using the above set options */
+	ret = krb5_verify_user_opt(context, userP, pass, &krb_verify_options);
+
+	/* We are done with the keytab, close it */
+        ret2 =  krb5_kt_close(context, keytab);
+
+	if (ret == 0)
+		return RLM_MODULE_OK;
+
+	radlog(L_AUTH, "rlm_krb5: failed verify_user: %s (%s@%s )",
+	       error_message(ret),
+	       *userP->name.name_string.val,
+	       userP->realm);
+
+	return RLM_MODULE_REJECT;
 }
 
 #endif /* HEIMDAL_KRB5 */
