--- src/session.c.orig	2013-06-17 17:28:14.000000000 +0400
+++ src/session.c	2013-10-25 22:01:39.000000000 +0400
@@ -1428,9 +1428,9 @@
 		/* Now we can add the server name to a header (if requested) */
 		/* check for HTTP mode and proxy server_name_hdr_name != NULL */
 		if ((s->flags & SN_BE_ASSIGNED) &&
-			(s->be->mode == PR_MODE_HTTP) &&
-			(s->be->server_id_hdr_name != NULL)) {
-
+		   (s->be->mode == PR_MODE_HTTP) &&
+                   (s->be->server_id_hdr_name != NULL) &&
+                   (s->srv)) {
 			http_send_name_header(&s->txn,
 					      &s->txn.req,
 					      s->req,
