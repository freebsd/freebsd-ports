--- webmail/folder.c.orig	2008-07-20 19:00:33.000000000 +0200
+++ webmail/folder.c	2009-06-04 08:32:54.000000000 +0200
@@ -247,6 +247,18 @@
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
 void folder_delmsgs(const char *dir, size_t pos)
 {
 	int	rc=0;
@@ -317,6 +329,16 @@
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
 
@@ -441,7 +463,7 @@
 
 	folder_navigate(dir, pos, highend, morebefore, moreafter);
 
-	printf("<table width=\"100%%\" border=\"0\" cellspacing=\"0\" cellpadding=\"4\"><tr class=\"folder-index-header\"><th align=\"center\">%s</th><th>&nbsp;</th><th>%s</th><th>%s</th><th>%s</th><th>%s</th></tr>\n",
+	printf("<table width=\"100%%\" border=\"0\" cellspacing=\"0\" cellpadding=\"4\"><tr class=\"folder-index-header\"><th align=\"center\">%s</th><th>&nbsp;</th><th>&nbsp;</th><th>&nbsp;</th><th>%s</th><th>%s</th><th>%s</th><th>%s</th></tr>\n",
 		getarg("NUM"),
 		getarg("DATE"),
 		(strncmp(dir, INBOX "." SENT, sizeof(INBOX)+sizeof(SENT)-1) &&
@@ -486,12 +508,13 @@
 		if ((q=strrchr(p, '/')) != 0)
 			p=q+1;
 
-		printf("<tr class=\"folder-index-bg-%d\" id=\"row%d\"><td align=\"right\" class=\"message-number\">%s%ld.%s</td><td class=\"message-status\"><input type=\"checkbox\" name=\"MOVE-%ld\" id=\"MOVE-%ld",
+		printf("<tr class=\"folder-index-bg-%d\" id=\"row%d\"><td align=\"right\" class=\"message-number\">%s%ld.%s</td><td class=\"message-flag\">%s</td><td class=\"message-select\"><input type=\"checkbox\" name=\"MOVE-%ld\" id=\"MOVE-%ld",
 		       (i & 1)+1,
 		       i,
 		       folder_index_entry_start,
 		       (long)(i+pos+1),
 		       folder_index_entry_end,
+		       maildirfile_flag(MSGINFO_FILENAME(contents[i])) ? "<font color=\"red\">!</font>" : "",
 		       (long) (pos+i),
 		       (long) (pos+i));
 		printf("\" onchange=\"setsel('MOVE-%ld', 'row%d', 'folder-index-bg-%d');\"%s /><input type=\"hidden\" name=\"MOVEFILE-%ld\" value=\"",
@@ -499,7 +522,7 @@
 			(type[0] == MSGTYPE_DELETED ? " disabled=\"disabled\"":""),
 			(long)(pos+i));
 		output_attrencoded(p);
-		printf("\" />&nbsp;%s%s%s</td><td class=\"message-date\">%s",
+		printf("\" /></td><td class=\"message-status\">%s%s%s</td><td class=\"message-date\">%s",
 		       folder_index_entry_start,
 		       type,
 		       folder_index_entry_end,
@@ -545,9 +568,9 @@
 
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
@@ -578,7 +601,7 @@
 	}
 	if (!found && nomsg)
 	{
-		puts("<tr class=\"folder-index-bg-1\"><td colspan=\"6\" align=\"left\"><p>");
+		puts("<tr class=\"folder-index-bg-1\"><td colspan=\"8\" align=\"left\"><p>");
 		puts(nomsg);
 		puts("<br /></p></td></tr>");
 		printf("</table>\n");
@@ -3364,7 +3387,7 @@
 	if ((strcmp(sqwebmail_folder, INBOX "." TRASH) == 0) && (strlen(getarg("PURGEALL"))))
 	    printf("<input type=\"submit\" name=\"cmdpurgeall\" value=\"%s\" onclick=\"javascript: return deleteAll();\" />", 
 		getarg("PURGEALL"));
-	printf("<input type=\"submit\" name=\"cmddel\" value=\"%s\" />%s<select name=\"moveto\">",
+	printf("<input type=\"submit\" name=\"cmddel\" value=\"%s\" />, <input type=\"submit\" name=\"cmdmark\" value=\"Mark\" />, <input type=\"submit\" name=\"cmdunmark\" value=\"Unmark\" />%s<select name=\"moveto\">",
 		strcmp(sqwebmail_folder, INBOX "." TRASH) == 0
 		? purgelab:deletelab,
 		movelab);
