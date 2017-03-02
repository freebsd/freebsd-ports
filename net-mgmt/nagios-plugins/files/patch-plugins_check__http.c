From 7300528aca1da07b93cab52493552b445b1c276b Mon Sep 17 00:00:00 2001
From: "John C. Frickson" <jfrickson@nagios.com>
Date: Mon, 27 Feb 2017 15:29:06 -0600
Subject: [PATCH] check_http reports warning where it should report ok with -e

Fix for issue #236
--- plugins/check_http.c.orig	2017-01-19 16:01:31 UTC
+++ plugins/check_http.c
@@ -1263,12 +1263,14 @@ check_http (void)
   /* server errors result in a critical state */
   else if (http_status >= 500) {
     xasprintf (&msg, _("%s%s - "), msg, status_line);
-    result = STATE_CRITICAL;
+    if (bad_response || !server_expect_yn)
+       result = STATE_CRITICAL;
   }
   /* client errors result in a warning state */
   else if (http_status >= 400) {
     xasprintf (&msg, _("%s%s - "), msg, status_line);
-    result = max_state_alt(STATE_WARNING, result);
+    if (bad_response || !server_expect_yn)
+      result = max_state_alt(STATE_WARNING, result);
   }
   /* check redirected page if specified */
   else if (http_status >= 300) {
