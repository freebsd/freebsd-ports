diff --git src/providers/ldap/ldap_child.c src/providers/ldap/ldap_child.c
index 368bb91e1..1bc86ecb5 100644
--- src/providers/ldap/ldap_child.c
+++ src/providers/ldap/ldap_child.c
@@ -324,14 +324,14 @@ static krb5_error_code ldap_child_get_tgt_sync(TALLOC_CTX *memctx,
             full_princ = talloc_strdup(tmp_ctx, princ_str);
         }
     } else {
-        char hostname[HOST_NAME_MAX + 1];
+        char hostname[_POSIX_HOST_NAME_MAX + 1];
 
-        ret = gethostname(hostname, sizeof(hostname));
+        ret = gethostname(hostname, _POSIX_HOST_NAME_MAX);
         if (ret == -1) {
             krberr = KRB5KRB_ERR_GENERIC;
             goto done;
         }
-        hostname[HOST_NAME_MAX] = '\0';
+        hostname[_POSIX_HOST_NAME_MAX] = '\0';
 
         DEBUG(SSSDBG_TRACE_LIBS, "got hostname: [%s]\n", hostname);
 
