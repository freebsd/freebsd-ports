--- src/lib-storage/index/maildir/maildir-list.c.orig	Wed Feb 26 05:58:45 2003
+++ src/lib-storage/index/maildir/maildir-list.c	Sun Apr 20 02:36:41 2003
@@ -242,7 +242,8 @@
 			continue; /* ignore inboxes */
 
 		if (match == IMAP_MATCH_PARENT) {
-			ctx->list.flags = MAILBOX_NOSELECT;
+			ctx->list.flags =
+				MAILBOX_PLACEHOLDER | MAILBOX_CHILDREN;
 			while ((p = strrchr(fname, '.')) != NULL) {
 				fname = t_strdup_until(fname, p);
 				if (imap_match(ctx->glob, fname) > 0) {
