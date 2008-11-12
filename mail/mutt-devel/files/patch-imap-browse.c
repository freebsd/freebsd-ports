Index: imap/browse.c
Obtained from: http://dev.mutt.org/trac/changeset/5401%3Abba92e401440/imap/browse.c?old=5378%3Aac00273b3a88&old_path=imap%2Fbrowse.c
Bug description: http://dev.mutt.org/trac/ticket/3057
===================================================================
--- imap/browse.c
+++ imap/browse.c
@@ -229,5 +229,5 @@
   }
 
-  if (!imap_mxcmp(mx.mbox, idata->mailbox))
+  if (idata->ctx && !imap_mxcmp(mx.mbox, idata->mailbox))
   {
     state->new = idata->ctx->new;
