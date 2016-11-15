--- src/plugins/imapsieve/imap-sieve-storage.c.orig	2016-11-08 02:19:04 UTC
+++ src/plugins/imapsieve/imap-sieve-storage.c
@@ -531,7 +531,8 @@ imap_sieve_mailbox_transaction_begin(str
 	/* commence parent transaction */
 	t = lbox->super.transaction_begin(box, flags);
 
-	if (isuser == NULL || isuser->sieve_active)
+	if (isuser == NULL || isuser->sieve_active ||
+		isuser->cur_cmd == IMAP_SIEVE_CMD_NONE)
 		return t;
 
 	i_assert(isuser->client != NULL);
