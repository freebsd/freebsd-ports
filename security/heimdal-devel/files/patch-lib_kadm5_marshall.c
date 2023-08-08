--- lib/kadm5/marshall.c.orig	2022-11-17 16:55:32.000000000 -0800
+++ lib/kadm5/marshall.c	2022-11-24 08:47:49.092069000 -0800
@@ -463,10 +463,40 @@
     ret = krb5_ret_int32(sp, &mask);
     if (ret)
 	goto out;
+    if (mask & KADM5_CONFIG_REALM & KADM5_CONFIG_DBNAME
+	& KADM5_CONFIG_ACL_FILE & KADM5_CONFIG_STASH_FILE) {
+	    ret = EINVAL;
+	    goto out;
+    }
     params->mask = mask;
 
-    if(params->mask & KADM5_CONFIG_REALM)
+    if (params->mask & KADM5_CONFIG_REALM) {
 	ret = krb5_ret_string(sp, &params->realm);
+	if (params->realm == NULL) {
+	    ret = EINVAL;
+	    goto out;
+	}
+    }
+    if (params->mask & KADM5_CONFIG_DBNAME) {
+	ret = krb5_ret_string(sp, &params->dbname);
+	if (params->dbname == NULL) {
+	    ret = EINVAL;
+	    goto out;
+	}
+    }
+    if (params->mask & KADM5_CONFIG_ACL_FILE) {
+	ret = krb5_ret_string(sp, &params->acl_file);
+	if (params->acl_file == NULL) {
+	    ret = EINVAL;
+	    goto out;
+	}
+    }
+    if (params->mask & KADM5_CONFIG_STASH_FILE) {
+	ret = krb5_ret_string(sp, &params->stash_file);
+	if (params->stash_file == NULL) {
+	    ret = EINVAL;
+	}
+    }
  out:
     krb5_storage_free(sp);
 
