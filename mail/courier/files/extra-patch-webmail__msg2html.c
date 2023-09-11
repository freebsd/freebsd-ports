--- libs/sqwebmail/msg2html.c.orig	2007-07-11 03:36:04.000000000 +0200
+++ libs/sqwebmail/msg2html.c	2007-12-21 08:42:02.000000000 +0100
@@ -451,6 +451,7 @@
 char	*header, *value;
 char	*save_subject=0;
 char	*save_date=0;
+char	*save_xface=0;
 off_t	start_pos, end_pos, start_body;
 struct	rfc2045id *p, newpart;
 off_t	dummy;
@@ -523,6 +524,13 @@
 			free(header);
 			continue;
 		}
+		if (strcmp(header, "x-face") == 0)
+		{
+			if (save_xface)	free(save_xface);
+			save_xface=strdup(value);
+			free(header);
+			continue;
+		}
 		if (isaddressheader(header))
 		{
 			print_header_uc(info, header);
@@ -575,7 +583,18 @@
 	if (flag && info->message_rfc822_action)
 		(*info->message_rfc822_action)(idptr);
 
-	printf("</table>\n<hr width=\"100%%\" />\n");
+	if (save_xface)
+	{
+		char *q=cgiurlencode(save_xface);
+		printf("</table>\n</td><td align=\"right\"><img width=\"48\" heigth=\"48\" src=\"http://www.dairiki.org/xface/xface.php?xface=");
+	        printf("%s", q);
+		printf("&amp;preview=1\"></td></tr><tr><td colspan=\"2\"><hr width=\"100%%\">\n");
+	        free(q);
+	}
+	else
+	{
+		printf("</table>\n<hr width=\"100%%\" />\n");
+	}
 
 	if (!flag && info->gpgdir && libmail_gpg_has_gpg(info->gpgdir) == 0
 	    && libmail_gpgmime_has_mimegpg(rfc)
