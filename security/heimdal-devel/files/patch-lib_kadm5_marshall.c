--- lib/kadm5/marshall.c.orig	2022-11-17 16:55:32.000000000 -0800
+++ lib/kadm5/marshall.c	2022-11-24 08:17:04.255672000 -0800
@@ -465,8 +465,12 @@
 	goto out;
     params->mask = mask;
 
-    if(params->mask & KADM5_CONFIG_REALM)
+    if (params->mask & KADM5_CONFIG_REALM) {
 	ret = krb5_ret_string(sp, &params->realm);
+	if (params->realm == NULL) {
+	    ret = EINVAL;
+	}
+    }
  out:
     krb5_storage_free(sp);
 
