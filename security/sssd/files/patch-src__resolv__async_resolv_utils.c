--- src/resolv/async_resolv_utils.c.orig	2020-03-17 13:31:28 UTC
+++ src/resolv/async_resolv_utils.c
@@ -45,7 +45,7 @@ resolv_get_domain_send(TALLOC_CTX *mem_ctx,
     struct resolv_get_domain_state *state = NULL;
     struct tevent_req *req = NULL;
     struct tevent_req *subreq = NULL;
-    char system_hostname[HOST_NAME_MAX + 1];
+    char system_hostname[_POSIX_HOST_NAME_MAX + 1];
     errno_t ret;
 
     req = tevent_req_create(mem_ctx, &state,
@@ -57,14 +57,14 @@ resolv_get_domain_send(TALLOC_CTX *mem_ctx,
 
     if (hostname == NULL) {
         /* use system hostname */
-        ret = gethostname(system_hostname, sizeof(system_hostname));
+        ret = gethostname(system_hostname, _POSIX_HOST_NAME_MAX);
         if (ret) {
             ret = errno;
             DEBUG(SSSDBG_CRIT_FAILURE, "gethostname() failed: [%d]: %s\n",
                                         ret, strerror(ret));
             goto immediately;
         }
-        system_hostname[HOST_NAME_MAX] = '\0';
+        system_hostname[_POSIX_HOST_NAME_MAX] = '\0';
         hostname = system_hostname;
     }
 
