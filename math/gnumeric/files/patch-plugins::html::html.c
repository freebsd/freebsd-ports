--- plugins/html/html.c.orig	Sun Sep 19 16:34:22 2004
+++ plugins/html/html.c	Sun Sep 19 16:34:43 2004
@@ -410,6 +410,7 @@
 "</HEAD>\n<BODY>\n", fp);
 		break;
 	default:
+		break;
 	}
 
 	sheets = workbook_sheets (wb);
