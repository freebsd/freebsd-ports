--- src/dialogs/kz-copy-format-dialog.c.orig	Fri Jul  1 19:54:45 2005
+++ src/dialogs/kz-copy-format-dialog.c	Fri Jul  1 19:55:06 2005
@@ -476,9 +476,9 @@
 
 	for(i = 1;i < 100;i++)
 	{
-		copy_format_data = g_new0(CopyFormat, 1);
 		gchar *title;
 		gchar *format;
+		copy_format_data = g_new0(CopyFormat, 1);
 
 		g_sprintf(title_directive, "copy_document_format_title%d", i);
 		g_sprintf(format_directive,  "copy_document_format%d", i);
