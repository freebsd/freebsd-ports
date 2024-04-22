--- src/util/sss_sockets.c.orig	2023-05-05 08:11:07 UTC
+++ src/util/sss_sockets.c
@@ -144,18 +144,6 @@ errno_t set_fd_common_opts(int fd, int timeout)
                   "setsockopt SO_SNDTIMEO failed.[%d][%s].\n", ret,
                   strerror(ret));
         }
-
-        if (domain != AF_UNIX && type == SOCK_STREAM) {
-            milli = timeout * 1000; /* timeout in milliseconds */
-            ret = setsockopt(fd, IPPROTO_TCP, TCP_USER_TIMEOUT, &milli,
-                            sizeof(milli));
-            if (ret != 0) {
-                ret = errno;
-                DEBUG(SSSDBG_FUNC_DATA,
-                    "setsockopt TCP_USER_TIMEOUT failed.[%d][%s].\n", ret,
-                    strerror(ret));
-            }
-        }
     }
 
     return EOK;
@@ -258,7 +246,7 @@ static void sssd_async_connect_done(struct tevent_cont
 
     talloc_zfree(fde);
 
-    if (ret == EOK) {
+    if (ret == EOK || ret == EISCONN) {
         tevent_req_done(req);
     } else {
         ret = errno;
