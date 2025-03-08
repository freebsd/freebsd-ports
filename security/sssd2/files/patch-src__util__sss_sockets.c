--- src/util/sss_sockets.c.orig	2025-05-07 09:36:03 UTC
+++ src/util/sss_sockets.c
@@ -260,7 +260,7 @@ static void sssd_async_connect_done(struct tevent_cont
 
     talloc_zfree(fde);
 
-    if (ret == EOK) {
+    if (ret == EOK || ret == EISCONN) {
         tevent_req_done(req);
     } else {
         ret = errno;
