diff --git src/dm_db.c b/src/dm_db.c
index 559d83c..529a48e 100644
--- src/dm_db.c
+++ src/dm_db.c
@@ -1832,7 +1832,9 @@ char * db_get_message_lines(uint64_t message_idnr, long lines)
 		return NULL;
 
 	msg = dbmail_message_new(NULL);
-	msg = dbmail_message_retrieve(msg, physmessage_id);
+	if (! (msg = dbmail_message_retrieve(msg, physmessage_id)))
+		return NULL;
+
 	stream = msg->crlf;
 
 	if (lines >=0) {
