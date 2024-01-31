--- src/dird/getmsg.c.orig	2023-05-02 09:50:49 UTC
+++ src/dird/getmsg.c
@@ -251,6 +251,14 @@ int bget_dirmsg(JCR *jcr, BSOCK *bs, BSOCK_CLIENT_TYPE
          if (*msg == ' ') {
             msg++;                    /* skip leading space */
          }
+         /* Fix to support old FDs */
+         if (role == BSOCK_TYPE_FD && jcr->client_version > 0 && jcr->client_version < 130000) {
+            type = type + 1; /* Adding M_EVENTS pushed all old events by 1, we fix it automatically here */
+         }
+         if (type == M_ABORT) { // not allowed here
+            Jmsg1(jcr, M_ERROR, 0, _("Malformed message: %s\n"), bs->msg);
+            continue;
+         }
          Dmsg1(900, "Dispatch msg: %s", msg);
          dispatch_message(jcr, type, mtime, msg);
          continue;
