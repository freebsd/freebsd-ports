--- ./outgoing.c.orig	2014-04-21 16:56:02.000000000 +0200
+++ ./outgoing.c	2014-06-08 18:17:48.000000000 +0200
@@ -23,6 +23,13 @@
 
 #include "serf_private.h"
 
+/* Some implementations -like Windows- report some hangup errors via a
+   different event than the specific HUP event. */
+#define APR_STATUS_IMPLIES_HANGUP(status)               \
+        (APR_STATUS_IS_ECONNRESET(status) ||            \
+         APR_STATUS_IS_ECONNABORTED(status) ||          \
+         status == SERF_ERROR_REQUEST_LOST)
+
 /* cleanup for sockets */
 static apr_status_t clean_skt(void *data)
 {
@@ -922,8 +929,12 @@
                                             request->handler_baton,
                                             pool);
 
-        if (SERF_BUCKET_READ_ERROR(status)) {
-            /* Report the request as 'died'/'cancelled' to the application */
+        if (SERF_BUCKET_READ_ERROR(status)
+            && !APR_STATUS_IMPLIES_HANGUP(status)) {
+
+            /* Report the request as 'died'/'cancelled' to the application,
+               but only if our caller doesn't handle this status specifically,
+               with something like a retry */
             (void)(*request->handler)(request,
                                       NULL,
                                       request->handler_baton,
@@ -1128,10 +1139,12 @@
 
         /* Some systems will not generate a HUP poll event so we have to
          * handle the ECONNRESET issue and ECONNABORT here.
+         *
+         * ### Update similar code in handle_response() if this condition
+         *     changes, or requests will get lost and/or accidentally reported
+         *     cancelled.
          */
-        if (APR_STATUS_IS_ECONNRESET(status) ||
-            APR_STATUS_IS_ECONNABORTED(status) ||
-            status == SERF_ERROR_REQUEST_LOST) {
+        if (APR_STATUS_IMPLIES_HANGUP(status)) {
             /* If the connection had ever been good, be optimistic & try again.
              * If it has never tried again (incl. a retry), fail.
              */
