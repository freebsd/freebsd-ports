--- lib/kadm5/marshall.c.orig	2022-09-15 16:54:19.000000000 -0700
+++ lib/kadm5/marshall.c	2022-11-24 08:26:55.920305000 -0800
@@ -409,8 +409,12 @@
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
 
