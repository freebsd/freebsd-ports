--- src/util/sss_ldap.c.orig	2014-09-17 13:01:37 UTC
+++ src/util/sss_ldap.c
@@ -206,6 +206,9 @@ static void sdap_async_sys_connect_done(struct tevent_
     errno = 0;
     ret = connect(state->fd, (struct sockaddr *) &state->addr,
                   state->addr_len);
+    if (errno == EISCONN) {
+        ret = EOK;
+    }
     if (ret != EOK) {
         ret = errno;
         if (ret == EINPROGRESS || ret == EINTR) {
@@ -346,7 +349,7 @@ struct tevent_req *sss_ldap_init_send(TALLOC_CTX *mem_
           "Using file descriptor [%d] for LDAP connection.\n", state->sd);
 
     subreq = sdap_async_sys_connect_send(state, ev, state->sd,
-                                         (struct sockaddr *) addr, addr_len);
+                                         (struct sockaddr *) addr, sizeof(struct sockaddr));
     if (subreq == NULL) {
         ret = ENOMEM;
         DEBUG(SSSDBG_CRIT_FAILURE, "sdap_async_sys_connect_send failed.\n");
