--- src/dm_imapsession.c.orig	2020-07-23 04:06:59 UTC
+++ src/dm_imapsession.c
@@ -804,9 +804,10 @@ static void _fetch_headers(ImapSession *self, body_fet
 			"m.mailbox_idnr = %" PRIu64 " "
 			"AND m.message_idnr %s "
 			"AND status < %d "
-			//"AND n.headername %s IN ('%s') "	//old, from the sql point of view is slow
-			"having seq %s %d "			//patch Cosmin Cioranu, removing the above conditions needs a restriction, patched added
-			"ORDER BY message_idnr, seq",
+			//"AND n.headername %s IN ('%s') "	//old, from the sql point of view is slow, CC 2020
+			"GROUP By m.message_idnr, n.headername, v.headervalue "
+			"having seq %s %d "
+			"ORDER BY m.message_idnr, seq",
 			not?"":fieldorder->str,
 			DBPFX, DBPFX, DBPFX, DBPFX,
 			self->mailbox->id, p_string_str(range),
