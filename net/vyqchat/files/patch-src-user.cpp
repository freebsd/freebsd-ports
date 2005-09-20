--- src/user.cpp	Mon Jul 18 21:54:08 2005
+++ src/user.cpp	Sun Sep 18 21:48:55 2005
@@ -42,7 +42,9 @@
 
 int User::height(const QListBox *lb) const/*{{{*/
 {
-	return QMAX(lb->fontMetrics().height(), Icons::icon_user.pixmap(QIconSet::Small, true).height());
+	int h1 = lb->fontMetrics().height();
+	int h2 = Icons::icon_user.pixmap(QIconSet::Small, true).height();
+	return QMAX(h1, h2);
 }/*}}}*/
 
 int User::width(const QListBox *lb) const/*{{{*/
