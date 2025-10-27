--- libs/sqwebmail/folder.c.orig	2025-05-12 00:23:26 UTC
+++ libs/sqwebmail/folder.c
@@ -251,6 +251,18 @@ static int groupmove(const char *folder, const char *f
 	return (maildir_msgmovefile(folder, file, cgi("moveto"), pos));
 }
 
+static int groupmark(const char *folder, const char *file, size_t pos)
+{
+	maildir_msgmarkfile(folder, file, pos);
+	return (0);
+}
+
+static int groupunmark(const char *folder, const char *file, size_t pos)
+{
+	maildir_msgunmarkfile(folder, file, pos);
+	return (0);
+}
+
 static const char *do_folder_delmsgs(const char *dir, size_t pos)
 {
 	int	rc=0;
@@ -320,6 +332,16 @@ static const char *do_folder_delmsgs(const char *dir, 
 		rc=group_movedel( dir, &groupmove );
 		maildir_savefoldermsgs(dir);
 	}
+	else if (*cgi("cmdmark"))
+	{
+		rc=group_movedel( dir, &groupmark );
+		maildir_savefoldermsgs(dir);
+	} 
+	else if (*cgi("cmdunmark"))
+	{
+		rc=group_movedel( dir, &groupunmark );
+		maildir_savefoldermsgs(dir);
+	}
 
 	maildir_cleanup();
 
@@ -505,7 +527,7 @@ unsigned long *last_message_searched_ptr=NULL;
 	folder_navigate(dir, pos, highend, morebefore, moreafter,
 			last_message_searched_ptr);
 
-	printf("<table width=\"100%%\" border=\"0\" cellspacing=\"0\" cellpadding=\"4\"><tr class=\"folder-index-header\"><th align=\"center\">%s</th><th>&nbsp;</th><th>%s</th><th>%s</th><th>%s</th><th>%s</th></tr>\n",
+	printf("<table width=\"100%%\" border=\"0\" cellspacing=\"0\" cellpadding=\"4\"><tr class=\"folder-index-header\"><th align=\"center\">%s</th><th>&nbsp;</th><th>&nbsp;</th><th>&nbsp;</th><th>%s</th><th>%s</th><th>%s</th><th>%s</th></tr>\n",
 		getarg("NUM"),
 		getarg("DATE"),
 		(strncmp(dir, INBOX "." SENT, sizeof(INBOX)+sizeof(SENT)-1) &&
@@ -526,9 +548,9 @@ unsigned long *last_message_searched_ptr=NULL;
 
 	if (found)
 	{
-		puts("<tr class=\"folder-index-bg-1\"><td colspan=\"6\"><hr /></td></tr>");
-		puts("<tr class=\"folder-index-bg-2\"><td>&nbsp;</td>");
-		puts("<td colspan=\"5\">");
+		puts("<tr class=\"folder-index-bg-3\"><td colspan=\"8\"><hr /></td></tr>");
+		puts("<tr class=\"folder-index-bg-4\"><td>&nbsp;</td>");
+		puts("<td colspan=\"7\">");
 
 		puts("<script type=\"text/javascript\">");
 		puts("/* <![CDATA[ */");
@@ -560,7 +582,7 @@ unsigned long *last_message_searched_ptr=NULL;
 	}
 	if (!found && nomsg)
 	{
-		puts("<tr class=\"folder-index-bg-1\"><td colspan=\"6\" align=\"left\"><p>");
+		puts("<tr class=\"folder-index-bg-1\"><td colspan=\"8\" align=\"left\"><p>");
 		puts(nomsg);
 		puts("<br /></p></td></tr>");
 		printf("</table>\n");
@@ -625,12 +647,13 @@ static void show_msg(const char *dir,
 	if ((q=strrchr(p, '/')) != 0)
 		p=q+1;
 
-	printf("<tr class=\"folder-index-bg-%d\" id=\"row%d\"><td align=\"right\" class=\"message-number\">%s%ld.%s</td><td class=\"message-status\"><input type=\"checkbox\" name=\"MOVE-%ld\" id=\"MOVE-%ld",
+	printf("<tr class=\"folder-index-bg-%d\" id=\"row%d\"><td align=\"right\" class=\"message-number\">%s%ld.%s</td><td class=\"message-flag\">%s</td><td class=\"message-select\"><input type=\"checkbox\" name=\"MOVE-%ld\" id=\"MOVE-%ld",
 	       (row & 1)+1,
 	       row,
 	       folder_index_entry_start,
 	       (long)(msgnum+1),
 	       folder_index_entry_end,
+	       maildirfile_flag(MSGINFO_FILENAME(msg)) ? "<font color=\"red\">!</font>" : "",
 	       (long) (msgnum),
 	       (long) (msgnum));
 	printf("\" onchange=\"setsel('MOVE-%ld', 'row%d', 'folder-index-bg-%d');\"%s /><input type=\"hidden\" name=\"MOVEFILE-%ld\" value=\"",
@@ -638,7 +661,7 @@ static void show_msg(const char *dir,
 	       (type[0] == MSGTYPE_DELETED ? " disabled=\"disabled\"":""),
 	       (long)(msgnum));
 	output_attrencoded(p);
-	printf("\" />&nbsp;%s%s%s</td><td class=\"message-date\">%s",
+	printf("\" /></td><td class=\"message-status\">%s%s%s</td><td class=\"message-date\">%s",
 	       folder_index_entry_start,
 	       type,
 	       folder_index_entry_end,
@@ -3640,7 +3663,7 @@ void folder_showtransfer()
 	if ((strcmp(sqwebmail_folder, INBOX "." TRASH) == 0) && (strlen(getarg("PURGEALL"))))
 	    printf("<input type=\"submit\" name=\"cmdpurgeall\" value=\"%s\" onclick=\"javascript: return deleteAll();\" />",
 		getarg("PURGEALL"));
-	printf("<input type=\"submit\" name=\"cmddel\" value=\"%s\" />%s<select name=\"moveto\">",
+	printf("<input type=\"submit\" name=\"cmddel\" value=\"%s\" />, <input type=\"submit\" name=\"cmdmark\" value=\"Mark\" />, <input type=\"submit\" name=\"cmdunmark\" value=\"Unmark\" />%s<select name=\"moveto\">",
 		strcmp(sqwebmail_folder, INBOX "." TRASH) == 0
 		? purgelab:deletelab,
 		movelab);
