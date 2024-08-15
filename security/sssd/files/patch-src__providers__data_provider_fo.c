--- src/providers/data_provider_fo.c.orig	2020-03-17 13:31:28 UTC
+++ src/providers/data_provider_fo.c
@@ -235,18 +235,18 @@ errno_t be_fo_set_dns_srv_lookup_plugin(struct be_ctx 
                                         const char *hostname)
 {
     struct fo_resolve_srv_dns_ctx *srv_ctx = NULL;
-    char resolved_hostname[HOST_NAME_MAX + 1];
+    char resolved_hostname[_POSIX_HOST_NAME_MAX + 1];
     errno_t ret;
 
     if (hostname == NULL) {
-        ret = gethostname(resolved_hostname, sizeof(resolved_hostname));
+        ret = gethostname(resolved_hostname, _POSIX_HOST_NAME_MAX);
         if (ret != EOK) {
             ret = errno;
             DEBUG(SSSDBG_CRIT_FAILURE,
                   "gethostname() failed: [%d]: %s\n", ret, strerror(ret));
             return ret;
         }
-        resolved_hostname[HOST_NAME_MAX] = '\0';
+        resolved_hostname[_POSIX_HOST_NAME_MAX] = '\0';
         hostname = resolved_hostname;
     }
 
