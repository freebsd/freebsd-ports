--- src/acl/external/kerberos_ldap_group/support_krb5.cc.orig	2020-04-19 12:38:51 UTC
+++ src/acl/external/kerberos_ldap_group/support_krb5.cc
@@ -467,10 +467,15 @@ krb5_create_cache(char *domain, char *service_principa
                 }
 
                 // overwrite limitation of enctypes
+#if USE_HEIMDAL_KRB5
+                creds->session.keytype = 0;
+                if (creds->session.keyvalue.length>0)
+                    krb5_free_keyblock_contents(kparam.context, &creds->session);
+#else
                 creds->keyblock.enctype = 0;
                 if (creds->keyblock.contents)
                     krb5_free_keyblock_contents(kparam.context, &creds->keyblock);
-
+#endif
                 code = krb5_get_credentials(kparam.context, 0, kparam.cc[ccindex], creds, &tgt_creds);
                 if (code) {
                     k5_error("Error while getting tgt", code);
