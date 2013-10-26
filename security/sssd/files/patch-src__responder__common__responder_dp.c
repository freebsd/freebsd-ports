From e98e59d8a6958ac1dc87b53f71aa9f51251b4568 Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 4 May 2013 16:08:11 +0200
Subject: [PATCH 16/34] patch-src__responder__common__responder_dp.c

---
 src/responder/common/responder_dp.c | 4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)

diff --git src/responder/common/responder_dp.c src/responder/common/responder_dp.c
index d15ca4d..3cb406a 100644
--- src/responder/common/responder_dp.c
+++ src/responder/common/responder_dp.c
@@ -213,7 +213,7 @@ static int sss_dp_get_reply(DBusPendingCall *pending,
     case DBUS_MESSAGE_TYPE_ERROR:
         if (strcmp(dbus_message_get_error_name(reply),
                    DBUS_ERROR_NO_REPLY) == 0) {
-            err = ETIME;
+            err = ETIMEDOUT;
             goto done;
         }
         DEBUG(0,("The Data Provider returned an error [%s]\n",
@@ -734,7 +734,7 @@ static void sss_dp_internal_get_done(DBusPendingCall *pending, void *ptr)
                            &sdp_req->dp_ret,
                            &sdp_req->err_msg);
     if (ret != EOK) {
-        if (ret == ETIME) {
+        if (ret == ETIMEDOUT) {
             sdp_req->dp_err = DP_ERR_TIMEOUT;
             sdp_req->dp_ret = ret;
             sdp_req->err_msg = talloc_strdup(sdp_req, "Request timed out");
-- 
1.8.0

