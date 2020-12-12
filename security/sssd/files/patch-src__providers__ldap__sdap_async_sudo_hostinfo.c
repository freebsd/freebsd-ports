diff --git src/providers/ldap/sdap_async_sudo_hostinfo.c src/providers/ldap/sdap_async_sudo_hostinfo.c
index a3c3e1068..f33299304 100644
--- src/providers/ldap/sdap_async_sudo_hostinfo.c
+++ src/providers/ldap/sdap_async_sudo_hostinfo.c
@@ -357,7 +357,7 @@ static struct tevent_req *sdap_sudo_get_hostnames_send(TALLOC_CTX *mem_ctx,
     struct tevent_req *subreq = NULL;
     struct sdap_sudo_get_hostnames_state *state = NULL;
     char *dot = NULL;
-    char hostname[HOST_NAME_MAX + 1];
+    char hostname[_POSIX_HOST_NAME_MAX + 1];
     int ret;
 
     req = tevent_req_create(mem_ctx, &state,
@@ -380,14 +380,14 @@ static struct tevent_req *sdap_sudo_get_hostnames_send(TALLOC_CTX *mem_ctx,
     /* get hostname */
 
     errno = 0;
-    ret = gethostname(hostname, sizeof(hostname));
+    ret = gethostname(hostname, _POSIX_HOST_NAME_MAX);
     if (ret != EOK) {
         ret = errno;
         DEBUG(SSSDBG_CRIT_FAILURE, "Unable to retrieve machine hostname "
                                     "[%d]: %s\n", ret, strerror(ret));
         goto done;
     }
-    hostname[HOST_NAME_MAX] = '\0';
+    hostname[_POSIX_HOST_NAME_MAX] = '\0';
 
     state->hostnames[0] = talloc_strdup(state->hostnames, hostname);
     if (state->hostnames[0] == NULL) {
