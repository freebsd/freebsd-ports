--- src/mod_auth_kerb.c.orig	Tue Aug 10 08:01:01 2004
+++ src/mod_auth_kerb.c	Wed Oct  5 20:25:38 2005
@@ -1108,6 +1108,7 @@
   spnego_oid.elements = (void *)"\x2b\x06\x01\x05\x05\x02";
 
   if (conf->krb_5_keytab) {
+#ifndef HEIMDAL
      char *ktname;
      /* we don't use the ap_* calls here, since the string passed to putenv()
       * will become part of the enviroment and shouldn't be free()ed by apache
@@ -1120,6 +1121,14 @@
      }
      sprintf(ktname, "KRB5_KTNAME=%s", conf->krb_5_keytab);
      putenv(ktname);
+#else
+     ret = gsskrb5_register_acceptor_identity(conf->krb_5_keytab);
+     if (ret) {
+	log_rerror(APLOG_MARK, APLOG_ERR, 0, r, "Setting KerberosV keytab failed: %s", strerror(errno));
+	ret = HTTP_INTERNAL_SERVER_ERROR;
+	goto end;
+     }
+#endif
   }
 
   ret = get_gss_creds(r, conf, &server_creds);
