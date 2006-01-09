--- kshutdown/mtip.cpp.orig	Mon Jan  9 18:34:50 2006
+++ kshutdown/mtip.cpp	Mon Jan  9 18:35:25 2006
@@ -41,7 +41,7 @@
 {
 	// valign and "center" ?
 	QString leftCell = "<td align=\"center\" valign=\"center\">";
-	leftCell += _iconPath.isEmpty() ? "&nbsp;" : ("<img src=\"" + _iconPath + "\">");
+	leftCell += _iconPath.isEmpty() ? QString::fromLatin1("&nbsp;") : ("<img src=\"" + _iconPath + "\">");
 	leftCell += "</td>";
 	setText(
 		"<qt>" \
