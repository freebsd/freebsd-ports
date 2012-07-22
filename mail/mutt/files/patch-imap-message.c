This patch fixes a segfault that happens when the IMAP server sends some
additional flags for the same message ID, see upstream bug
http://bugs.mutt.org/3288

--- imap/message.c
+++ imap/message.c
@@ -288,7 +288,7 @@
         continue;
       }
       /* May receive FLAGS updates in a separate untagged response (#2935) */
-      if (idx < ctx->msgcount)
+      if (ctx->hdrs[idx] != NULL)
       {
 	dprint (2, (debugfile, "imap_read_headers: message %d is not new\n",
 		    h.sid));
