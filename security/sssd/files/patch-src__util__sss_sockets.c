--- src/util/sss_sockets.c.orig	2020-03-17 13:31:28.000000000 +0000
+++ src/util/sss_sockets.c	2020-10-22 19:39:46.454834000 +0100
@@ -120,14 +120,16 @@
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
@@ -230,7 +232,7 @@
 
     talloc_zfree(fde);
 
-    if (ret == EOK) {
+    if (ret == EOK || ret == EISCONN) {
         tevent_req_done(req);
     } else {
         ret = errno;
@@ -313,7 +315,7 @@
           "Using file descriptor [%d] for the connection.\n", state->sd);
 
     subreq = sssd_async_connect_send(state, ev, state->sd,
-                                     (struct sockaddr *) addr, addr_len);
+                                     (struct sockaddr *) addr, sizeof(struct sockaddr));
     if (subreq == NULL) {
         ret = ENOMEM;
         DEBUG(SSSDBG_CRIT_FAILURE, "sssd_async_connect_send failed.\n");
