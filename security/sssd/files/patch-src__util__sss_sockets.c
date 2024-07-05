--- src/util/sss_sockets.c.orig	2020-03-17 13:31:28 UTC
+++ src/util/sss_sockets.c
@@ -120,14 +120,16 @@ static errno_t set_fd_common_opts(int fd, int timeout)
         }
 
         milli = timeout * 1000; /* timeout in milliseconds */
-        ret = setsockopt(fd, IPPROTO_TCP, TCP_USER_TIMEOUT, &milli,
-                         sizeof(milli));
-        if (ret != 0) {
-            ret = errno;
-            DEBUG(SSSDBG_FUNC_DATA,
-                  "setsockopt TCP_USER_TIMEOUT failed.[%d][%s].\n", ret,
-                  strerror(ret));
-        }
+        /* FreeBSD does not have TCP_USER_TIMEOUT option yet ....
+	 * ret = setsockopt(fd, IPPROTO_TCP, TCP_USER_TIMEOUT, &milli,
+         *                  sizeof(milli));
+         * if (ret != 0) {
+         *     ret = errno;
+         *     DEBUG(SSSDBG_FUNC_DATA,
+         *           "setsockopt TCP_USER_TIMEOUT failed.[%d][%s].\n", ret,
+         *           strerror(ret));
+         * }
+	 */
     }
 
     return EOK;
@@ -230,7 +232,7 @@ static void sssd_async_connect_done(struct tevent_cont
 
     talloc_zfree(fde);
 
-    if (ret == EOK) {
+    if (ret == EOK || ret == EISCONN) {
         tevent_req_done(req);
     } else {
         ret = errno;
@@ -313,7 +315,7 @@ struct tevent_req *sssd_async_socket_init_send(TALLOC_
           "Using file descriptor [%d] for the connection.\n", state->sd);
 
     subreq = sssd_async_connect_send(state, ev, state->sd,
-                                     (struct sockaddr *) addr, addr_len);
+                                     (struct sockaddr *) addr, sizeof(struct sockaddr));
     if (subreq == NULL) {
         ret = ENOMEM;
         DEBUG(SSSDBG_CRIT_FAILURE, "sssd_async_connect_send failed.\n");
