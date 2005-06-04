Index: src/procmsg.c
===================================================================
RCS file: /cvsroot/sylpheed-claws/sylpheed-claws/src/procmsg.c,v
retrieving revision 1.150.2.23
retrieving revision 1.150.2.24
diff -u -r1.150.2.23 -r1.150.2.24
--- src/procmsg.c	30 Apr 2005 16:47:39 -0000	1.150.2.23
+++ src/procmsg.c	19 May 2005 19:53:29 -0000	1.150.2.24
@@ -662,13 +662,6 @@
 	FILE *fp;
 	int hnum;
 	gchar buf[BUFFSIZE];
-	
-	g_return_val_if_fail(file != NULL, NULL);
-
-	if ((fp = fopen(file, "rb")) == NULL) {
-		FILE_OP_ERROR(file, "fopen");
-		return NULL;
-	}
 	static HeaderEntry qentry[] = {{"S:",    NULL, FALSE},
 				       {"SSV:",  NULL, FALSE},
 				       {"R:",    NULL, FALSE},
@@ -682,6 +675,13 @@
 				       {"X-Sylpheed-Encrypt:", NULL, FALSE},
 				       {"X-Sylpheed-Encrypt-Data:", NULL, FALSE},
 				       {NULL,    NULL, FALSE}};
+	
+	g_return_val_if_fail(file != NULL, NULL);
+
+	if ((fp = fopen(file, "rb")) == NULL) {
+		FILE_OP_ERROR(file, "fopen");
+		return NULL;
+	}
 
 	while ((hnum = procheader_get_one_field(buf, sizeof(buf), fp, qentry))
 	       != -1) {


Index: src/procmsg.c
===================================================================
RCS file: /cvsroot/sylpheed-claws/sylpheed-claws/src/procmsg.c,v
retrieving revision 1.150.2.24
retrieving revision 1.150.2.25
diff -u -r1.150.2.24 -r1.150.2.25
--- src/procmsg.c	19 May 2005 19:53:29 -0000	1.150.2.24
+++ src/procmsg.c	20 May 2005 16:24:11 -0000	1.150.2.25
@@ -722,9 +722,9 @@
 	cur = orig;
 	while (cur) {
 		gchar *file;
+		PrefsAccount *ac = procmsg_get_account_from_file(file);
 		msg = (MsgInfo *)cur->data;
 		file = folder_item_fetch_msg(queue, msg->msgnum);
-		PrefsAccount *ac = procmsg_get_account_from_file(file);
 		g_free(file);
 
 		if (last_account == NULL || (ac != NULL && ac == last_account)) {
