--- components/html-editor/popup.c.orig	Thu Jan 23 16:44:21 2003
+++ components/html-editor/popup.c	Sat Aug 14 00:58:07 2004
@@ -496,6 +496,7 @@
 			ADD_PROP (PARAGRAPH);
 			break;
 		default:
+			break;
 		}
 		if (obj->parent && obj->parent->parent && HTML_IS_TABLE_CELL (obj->parent->parent)) {
 			if (cd->format_html) {
