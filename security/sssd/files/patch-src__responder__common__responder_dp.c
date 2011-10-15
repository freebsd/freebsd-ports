--- ./src/responder/common/responder_dp.c.orig	2011-08-29 11:39:05.000000000 -0400
+++ ./src/responder/common/responder_dp.c	2011-10-13 12:15:03.000000000 -0400
@@ -210,7 +210,7 @@
                            &sdp_req->err_min,
                            &sdp_req->err_msg);
     if (ret != EOK) {
-        if (ret == ETIME) {
+        if (ret == ETIMEDOUT) {
             sdp_req->err_maj = DP_ERR_TIMEOUT;
             sdp_req->err_min = ret;
             sdp_req->err_msg = talloc_strdup(sdp_req, "Request timed out");
@@ -569,7 +569,7 @@
     case DBUS_MESSAGE_TYPE_ERROR:
         if (strcmp(dbus_message_get_error_name(reply),
                    DBUS_ERROR_NO_REPLY) == 0) {
-            err = ETIME;
+            err = ETIMEDOUT;
             goto done;
         }
         DEBUG(0,("The Data Provider returned an error [%s]\n",
