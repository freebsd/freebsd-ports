#
# Fixes of "keytab" keyword on the client side.
#
# https://github.com/cyrusimap/cyrus-sasl/commit/74faca7400f414784b5e2e136668e6f4ef0d6b96
# https://github.com/cyrusimap/cyrus-sasl/commit/7a95382c68e7187fe7407b2a94036d9ca3246e34
# https://github.com/cyrusimap/cyrus-sasl/commit/238380260fe623212c0f21d63e763b7a849540d1
#
--- plugins/gssapi.c.orig	2018-11-08 17:29:57 UTC
+++ plugins/gssapi.c
@@ -1668,8 +1668,10 @@ static int gssapi_client_mech_step(void *conn_context,
     if (clientoutlen)
         *clientoutlen = 0;
     
+#if 0
     params->utils->log(params->utils->conn, SASL_LOG_DEBUG,
 		       "GSSAPI client step %d", text->state);
+#endif
 
     switch (text->state) {
 
@@ -1777,6 +1779,39 @@ static int gssapi_client_mech_step(void *conn_context,
 	    req_flags = req_flags |  GSS_C_DELEG_FLAG;
 	}
 
+	/*
+	 * If caller didn't provide creds already.
+	 *
+	 * In the case of Kerberos, a client typically wants to use
+	 * a credential in either a keytab file or the credentials cache
+	 * of the current process context.  This code path will try to
+	 * find a credential in the specified keytab file,  then the
+	 * credentials cache.  The keytab file can be specified by
+	 * "keytab" option, and it is configured by using
+	 * gsskrb5_register_acceptor_identity() API when available.
+	 */
+	if (client_creds == GSS_C_NO_CREDENTIAL) {
+	    GSS_LOCK_MUTEX_CTX(params->utils, text);
+	    maj_stat = gss_acquire_cred(&min_stat,
+					text->server_name,
+					GSS_C_INDEFINITE,
+					GSS_C_NO_OID_SET,
+					GSS_C_INITIATE,
+					&text->client_creds, 
+					NULL, 
+					NULL);
+	    GSS_UNLOCK_MUTEX_CTX(params->utils, text);
+
+	    /*
+	     * Ignore the error intentionally.  The credential was
+	     * not found in the specified keytab file.
+	     */
+	    if (GSS_ERROR(maj_stat) == 0) {
+		client_creds = text->client_creds;
+	    }
+	}
+
+	/* Try the credentials cache. */
 	GSS_LOCK_MUTEX_CTX(params->utils, text);
 	maj_stat = gss_init_sec_context(&min_stat,
 					client_creds, /* GSS_C_NO_CREDENTIAL */
@@ -2227,16 +2262,55 @@ static sasl_client_plug_t gssapi_client_plugins[] = 
 #endif
 };
 
-int gssapiv2_client_plug_init(const sasl_utils_t *utils __attribute__((unused)), 
+int gssapiv2_client_plug_init(
+#ifndef HAVE_GSSKRB5_REGISTER_ACCEPTOR_IDENTITY
+    const sasl_utils_t *utils __attribute__((unused)),
+#else
+    const sasl_utils_t *utils,
+#endif
 			      int maxversion,
 			      int *out_version, 
 			      sasl_client_plug_t **pluglist,
 			      int *plugcount)
 {
+#ifdef HAVE_GSSKRB5_REGISTER_ACCEPTOR_IDENTITY
+    const char *keytab = NULL;
+    char keytab_path[1024];
+    unsigned int rl;
+#endif
+
     if (maxversion < SASL_CLIENT_PLUG_VERSION) {
 	SETERROR(utils, "Version mismatch in GSSAPI");
 	return SASL_BADVERS;
     }
+
+#ifdef HAVE_GSSKRB5_REGISTER_ACCEPTOR_IDENTITY
+    /* unfortunately, we don't check for readability of keytab if it's
+       the standard one, since we don't know where it is */
+    
+    /* FIXME: This code is broken */
+    
+    utils->getopt(utils->getopt_context, "GSSAPI", "keytab", &keytab, &rl);
+    if (keytab != NULL) {
+	if (access(keytab, R_OK) != 0) {
+	    utils->log(NULL, SASL_LOG_ERR,
+		       "Could not find keytab file: %s: %m", keytab);
+	    return SASL_FAIL;
+	}
+	
+	if(strlen(keytab) > sizeof(keytab_path)) {
+	    utils->log(NULL, SASL_LOG_ERR,
+		       "path to keytab is > %zu characters",
+		       sizeof(keytab_path));
+	    return SASL_BUFOVER;
+	}
+	
+	strncpy(keytab_path, keytab, sizeof(keytab_path));
+	keytab_path[sizeof(keytab_path) - 1] = '\0';
+	
+	gsskrb5_register_acceptor_identity(keytab_path);
+    }
+#endif
     
     *out_version = SASL_CLIENT_PLUG_VERSION;
     *pluglist = gssapi_client_plugins;
