--- ./src/providers/krb5/krb5_child.c.orig	2011-08-29 11:39:05.000000000 -0400
+++ ./src/providers/krb5/krb5_child.c	2011-10-13 12:15:03.000000000 -0400
@@ -39,6 +39,15 @@
 
 #define SSSD_KRB5_CHANGEPW_PRINCIPAL "kadmin/changepw"
 
+typedef struct _krb5_ticket_times {
+  krb5_timestamp authtime; /* XXX ? should ktime in KDC_REP == authtime
+			      in ticket? otherwise client can't get this */ 
+  krb5_timestamp starttime;           /* optional in ticket, if not present,
+					 use authtime */
+  krb5_timestamp endtime;
+  krb5_timestamp renew_till;
+} krb5_ticket_times;
+
 struct krb5_child_ctx {
     /* opts taken from kinit */
     /* in seconds */
@@ -100,10 +109,10 @@
 
 static krb5_context krb5_error_ctx;
 static const char *__krb5_error_msg;
-#define KRB5_DEBUG(level, krb5_error) do { \
-    __krb5_error_msg = sss_krb5_get_error_message(krb5_error_ctx, krb5_error); \
+#define KRB5_DEBUG(level, krb5_error, ctx) do {				\
+    __krb5_error_msg = sss_krb5_get_error_message(ctx, krb5_error); \
     DEBUG(level, ("%d: [%d][%s]\n", __LINE__, krb5_error, __krb5_error_msg)); \
-    sss_krb5_free_error_message(krb5_error_ctx, __krb5_error_msg); \
+    sss_krb5_free_error_message(ctx, __krb5_error_msg);			\
 } while(0);
 
 static void sss_krb5_expire_callback_func(krb5_context context, void *data,
@@ -267,13 +276,13 @@
 
     kerr = krb5_cc_resolve(ctx, tmp_ccname, &tmp_cc);
     if (kerr != 0) {
-        KRB5_DEBUG(1, kerr);
+      KRB5_DEBUG(1, kerr, ctx);
         goto done;
     }
 
     kerr = krb5_cc_initialize(ctx, tmp_cc, princ);
     if (kerr != 0) {
-        KRB5_DEBUG(1, kerr);
+      KRB5_DEBUG(1, kerr, ctx);
         goto done;
     }
     if (fd != -1) {
@@ -284,7 +293,7 @@
     if (creds == NULL) {
         kerr = create_empty_cred(ctx, princ, &l_cred);
         if (kerr != 0) {
-            KRB5_DEBUG(1, kerr);
+	  KRB5_DEBUG(1, kerr, ctx);
             goto done;
         }
     } else {
@@ -293,13 +302,13 @@
 
     kerr = krb5_cc_store_cred(ctx, tmp_cc, l_cred);
     if (kerr != 0) {
-        KRB5_DEBUG(1, kerr);
+      KRB5_DEBUG(1, kerr, ctx);
         goto done;
     }
 
     kerr = krb5_cc_close(ctx, tmp_cc);
     if (kerr != 0) {
-        KRB5_DEBUG(1, kerr);
+      KRB5_DEBUG(1, kerr, ctx);
         goto done;
     }
     tmp_cc = NULL;
@@ -420,7 +429,7 @@
             talloc_zfree(msg);
         }
     } else {
-        krb5_msg = sss_krb5_get_error_message(krb5_error_ctx, kerr);
+        krb5_msg = sss_krb5_get_error_message(kr->ctx, kerr);
         if (krb5_msg == NULL) {
             DEBUG(1, ("sss_krb5_get_error_message failed.\n"));
             return NULL;
@@ -429,7 +438,7 @@
         ret = pam_add_response(kr->pd, SSS_PAM_SYSTEM_INFO,
                                strlen(krb5_msg) + 1,
                                (const uint8_t *) krb5_msg);
-        sss_krb5_free_error_message(krb5_error_ctx, krb5_msg);
+        sss_krb5_free_error_message(kr->ctx, krb5_msg);
     }
     if (ret != EOK) {
         DEBUG(1, ("pam_add_response failed.\n"));
@@ -527,7 +536,7 @@
             break;
         }
 
-        kerr = krb5_free_keytab_entry_contents(kr->ctx, &entry);
+        kerr = krb5_kt_free_entry(kr->ctx, &entry);
         if (kerr != 0) {
             DEBUG(1, ("Failed to free keytab entry.\n"));
         }
@@ -575,7 +584,7 @@
     if (krb5_kt_close(kr->ctx, keytab) != 0) {
         DEBUG(1, ("krb5_kt_close failed"));
     }
-    if (krb5_free_keytab_entry_contents(kr->ctx, &entry) != 0) {
+    if (krb5_kt_free_entry(kr->ctx, &entry) != 0) {
         DEBUG(1, ("Failed to free keytab entry.\n"));
     }
     if (principal != NULL) {
@@ -605,13 +614,13 @@
     kerr = krb5_get_init_creds_keytab(ctx, &creds, princ, keytab, 0, NULL,
                                       &options);
     if (kerr != 0) {
-        KRB5_DEBUG(1, kerr);
+      KRB5_DEBUG(1, kerr, ctx);
         return kerr;
     }
 
     kerr = create_ccache_file(ctx, princ, ccname, &creds);
     if (kerr != 0) {
-        KRB5_DEBUG(1, kerr);
+      KRB5_DEBUG(1, kerr, ctx);
         goto done;
     }
     kerr = 0;
@@ -633,21 +642,21 @@
                                                   sss_krb5_expire_callback_func,
                                                   kr);
     if (kerr != 0) {
-        KRB5_DEBUG(1, kerr);
+      KRB5_DEBUG(1, kerr, kr->ctx);
         DEBUG(1, ("Failed to set expire callback, continue without.\n"));
     }
     kerr = krb5_get_init_creds_password(kr->ctx, kr->creds, kr->princ,
                                         password, sss_krb5_prompter, kr, 0,
                                         NULL, kr->options);
     if (kerr != 0) {
-        KRB5_DEBUG(1, kerr);
+      KRB5_DEBUG(1, kerr, kr->ctx);
         return kerr;
     }
 
     if (kr->validate) {
         kerr = validate_tgt(kr);
         if (kerr != 0) {
-            KRB5_DEBUG(1, kerr);
+	  KRB5_DEBUG(1, kerr, kr->ctx);
             return kerr;
         }
 
@@ -668,7 +677,7 @@
 
     kerr = create_ccache_file(kr->ctx, kr->princ, kr->ccname, kr->creds);
     if (kerr != 0) {
-        KRB5_DEBUG(1, kerr);
+      KRB5_DEBUG(1, kerr, kr->ctx);
         goto done;
     }
 
@@ -692,7 +701,7 @@
     krb5_error_code kerr = 0;
     char *pass_str = NULL;
     char *newpass_str = NULL;
-    int pam_status = PAM_SYSTEM_ERR;
+    int pam_status = PAM_SERVICE_ERR;
     int result_code = -1;
     krb5_data result_code_string;
     krb5_data result_string;
@@ -734,7 +743,7 @@
                                         changepw_princ,
                                         kr->options);
     if (kerr != 0) {
-        KRB5_DEBUG(1, kerr);
+      KRB5_DEBUG(1, kerr, kr->ctx);
         if (kerr == KRB5_KDC_UNREACH) {
             pam_status = PAM_AUTHINFO_UNAVAIL;
         }
@@ -773,7 +782,7 @@
 
     if (kerr != 0 || result_code != 0) {
         if (kerr != 0) {
-            KRB5_DEBUG(1, kerr);
+	  KRB5_DEBUG(1, kerr, kr->ctx);
         } else {
             kerr = KRB5KRB_ERR_GENERIC;
         }
@@ -825,7 +834,7 @@
     memset(kr->pd->newauthtok, 0, kr->pd->newauthtok_size);
 
     if (kerr != 0) {
-        KRB5_DEBUG(1, kerr);
+      KRB5_DEBUG(1, kerr, kr->ctx);
         if (kerr == KRB5_KDC_UNREACH) {
             pam_status = PAM_AUTHINFO_UNAVAIL;
         }
@@ -846,7 +855,7 @@
     krb5_error_code kerr = 0;
     char *pass_str = NULL;
     char *changepw_princ = NULL;
-    int pam_status = PAM_SYSTEM_ERR;
+    int pam_status = PAM_SERVICE_ERR;
 
     if (kr->pd->authtok_type != SSS_AUTHTOK_TYPE_PASSWORD) {
         pam_status = PAM_CRED_INSUFFICIENT;
@@ -881,7 +890,7 @@
                                                                kr->options,
                                                                NULL, NULL);
         if (kerr != 0) {
-            KRB5_DEBUG(1, kerr);
+	  KRB5_DEBUG(1, kerr, kr->ctx);
             DEBUG(1, ("Failed to unset expire callback, continue ...\n"));
         }
         kerr = krb5_get_init_creds_password(kr->ctx, kr->creds, kr->princ,
@@ -899,7 +908,7 @@
     memset(kr->pd->authtok, 0, kr->pd->authtok_size);
 
     if (kerr != 0) {
-        KRB5_DEBUG(1, kerr);
+      KRB5_DEBUG(1, kerr, kr->ctx);
         switch (kerr) {
             case KRB5_KDC_UNREACH:
                     pam_status = PAM_AUTHINFO_UNAVAIL;
@@ -911,7 +920,7 @@
                     pam_status = PAM_CRED_ERR;
                     break;
             default:
-                    pam_status = PAM_SYSTEM_ERR;
+                    pam_status = PAM_SERVICE_ERR;
         }
     }
 
@@ -981,13 +990,13 @@
 
     kerr = krb5_cc_resolve(kr->ctx, ccname, &ccache);
     if (kerr != 0) {
-        KRB5_DEBUG(1, kerr);
+      KRB5_DEBUG(1, kerr, kr->ctx);
         goto done;
     }
 
     kerr = krb5_get_renewed_creds(kr->ctx, kr->creds, kr->princ, ccache, NULL);
     if (kerr != 0) {
-        KRB5_DEBUG(1, kerr);
+      KRB5_DEBUG(1, kerr, kr->ctx);
         if (kerr == KRB5_KDC_UNREACH) {
             status = PAM_AUTHINFO_UNAVAIL;
         }
@@ -997,7 +1006,7 @@
     if (kr->validate) {
         kerr = validate_tgt(kr);
         if (kerr != 0) {
-            KRB5_DEBUG(1, kerr);
+	  KRB5_DEBUG(1, kerr, kr->ctx);
             goto done;
         }
 
@@ -1019,13 +1028,13 @@
 
     kerr = krb5_cc_initialize(kr->ctx, ccache, kr->princ);
     if (kerr != 0) {
-        KRB5_DEBUG(1, kerr);
+      KRB5_DEBUG(1, kerr, kr->ctx);
         goto done;
     }
 
     kerr = krb5_cc_store_cred(kr->ctx, ccache, kr->creds);
     if (kerr != 0) {
-        KRB5_DEBUG(1, kerr);
+      KRB5_DEBUG(1, kerr, kr->ctx);
         goto done;
     }
 
@@ -1059,8 +1068,8 @@
 
     ret = create_ccache_file(kr->ctx, kr->princ, kr->ccname, NULL);
     if (ret != 0) {
-        KRB5_DEBUG(1, ret);
-        pam_status = PAM_SYSTEM_ERR;
+      KRB5_DEBUG(1, ret, kr->ctx);
+        pam_status = PAM_SERVICE_ERR;
     }
 
     ret = sendresponse(fd, ret, pam_status, kr);
@@ -1375,19 +1384,20 @@
 
     kerr = krb5_init_context(&kr->ctx);
     if (kerr != 0) {
-        KRB5_DEBUG(1, kerr);
+      /* FIXME: This sucks */
+      KRB5_DEBUG(1, kerr, kr->ctx);
         goto failed;
     }
 
     kerr = krb5_parse_name(kr->ctx, kr->upn, &kr->princ);
     if (kerr != 0) {
-        KRB5_DEBUG(1, kerr);
+      KRB5_DEBUG(1, kerr, kr->ctx);
         goto failed;
     }
 
     kerr = krb5_unparse_name(kr->ctx, kr->princ, &kr->name);
     if (kerr != 0) {
-        KRB5_DEBUG(1, kerr);
+      KRB5_DEBUG(1, kerr, kr->ctx);
         goto failed;
     }
 
@@ -1400,18 +1410,18 @@
 
     kerr = sss_krb5_get_init_creds_opt_alloc(kr->ctx, &kr->options);
     if (kerr != 0) {
-        KRB5_DEBUG(1, kerr);
+      KRB5_DEBUG(1, kerr, kr->ctx);
         goto failed;
     }
 
     /* A prompter is used to catch messages about when a password will
      * expired. The library shall not use the prompter to ask for a new password
      * but shall return KRB5KDC_ERR_KEY_EXP. */
-    krb5_get_init_creds_opt_set_change_password_prompt(kr->options, 0);
-    if (kerr != 0) {
-        KRB5_DEBUG(1, kerr);
-        goto failed;
-    }
+    //    krb5_get_init_creds_opt_set_change_password_prompt(kr->options, 0);
+    //    if (kerr != 0) {
+    //        KRB5_DEBUG(1, kerr, kr->ctx);
+    //        goto failed;
+    //    }
 
     lifetime_str = getenv(SSSD_KRB5_RENEWABLE_LIFETIME);
     if (lifetime_str == NULL) {
@@ -1422,7 +1432,7 @@
         if (kerr != 0) {
             DEBUG(1, ("krb5_string_to_deltat failed for [%s].\n",
                       lifetime_str));
-            KRB5_DEBUG(1, kerr);
+            KRB5_DEBUG(1, kerr, kr->ctx);
             goto failed;
         }
         krb5_get_init_creds_opt_set_renew_life(kr->options, lifetime);
@@ -1437,7 +1447,7 @@
         if (kerr != 0) {
             DEBUG(1, ("krb5_string_to_deltat failed for [%s].\n",
                       lifetime_str));
-            KRB5_DEBUG(1, kerr);
+            KRB5_DEBUG(1, kerr, kr->ctx);
             goto failed;
         }
         krb5_get_init_creds_opt_set_tkt_life(kr->options, lifetime);
@@ -1486,7 +1496,7 @@
                                      kr, &kr->fast_ccname);
             if (kerr != 0) {
                 DEBUG(1, ("check_fast_ccache failed.\n"));
-                KRB5_DEBUG(1, kerr);
+                KRB5_DEBUG(1, kerr, kr->ctx);
                 goto failed;
             }
 
@@ -1496,7 +1506,7 @@
             if (kerr != 0) {
                 DEBUG(1, ("sss_krb5_get_init_creds_opt_set_fast_ccache_name "
                           "failed.\n"));
-                KRB5_DEBUG(1, kerr);
+                KRB5_DEBUG(1, kerr, kr->ctx);
                 goto failed;
             }
 
@@ -1507,7 +1517,7 @@
                 if (kerr != 0) {
                     DEBUG(1, ("sss_krb5_get_init_creds_opt_set_fast_flags "
                               "failed.\n"));
-                    KRB5_DEBUG(1, kerr);
+                    KRB5_DEBUG(1, kerr, kr->ctx);
                     goto failed;
                 }
             }
