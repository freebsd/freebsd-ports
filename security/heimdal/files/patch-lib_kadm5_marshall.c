--- lib/kadm5/marshall.c.orig	2022-09-15 16:54:19.000000000 -0700
+++ lib/kadm5/marshall.c	2022-11-26 08:20:41.302104000 -0800
@@ -261,9 +261,9 @@
     int i;
     int32_t tmp;
 
-    if (mask & KADM5_PRINCIPAL)
-	krb5_ret_principal(sp, &princ->principal);
-
+    if (mask & KADM5_PRINCIPAL) 
+	if (krb5_ret_principal(sp, &princ->principal))
+	    return EINVAL;
     if (mask & KADM5_PRINC_EXPIRE_TIME) {
 	krb5_ret_int32(sp, &tmp);
 	princ->princ_expire_time = tmp;
@@ -282,9 +282,10 @@
     }
     if (mask & KADM5_MOD_NAME) {
 	krb5_ret_int32(sp, &tmp);
-	if(tmp)
-	    krb5_ret_principal(sp, &princ->mod_name);
-	else
+	if(tmp) {
+	    if (krb5_ret_principal(sp, &princ->mod_name))
+		return EINVAL;
+	} else
 	    princ->mod_name = NULL;
     }
     if (mask & KADM5_MOD_TIME) {
@@ -407,10 +408,40 @@
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
 
