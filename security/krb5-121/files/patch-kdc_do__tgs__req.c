--- kdc/do_tgs_req.c.orig	2023-07-10 13:58:20.000000000 -0700
+++ kdc/do_tgs_req.c	2023-08-14 07:23:14.383349000 -0700
@@ -1010,8 +1010,9 @@
     }
 
     if (t->req->kdc_options & (KDC_OPT_VALIDATE | KDC_OPT_RENEW)) {
-        /* Copy the whole header ticket except for authorization data. */
-        ticket_reply = *t->header_tkt;
+        /* Copy the header ticket server and all enc-part fields except for
+         * authorization data. */
+        ticket_reply.server = t->header_tkt->server;
         enc_tkt_reply = *t->header_tkt->enc_part2;
         enc_tkt_reply.authorization_data = NULL;
     } else {
