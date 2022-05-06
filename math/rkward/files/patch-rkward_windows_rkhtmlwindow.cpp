--- rkward/windows/rkhtmlwindow.cpp.orig	2022-04-16 22:02:17 UTC
+++ rkward/windows/rkhtmlwindow.cpp
@@ -109,8 +109,9 @@ class RKWebPage : public QWebEnginePage { (public)
 	QUrl url () {
 		return mainFrame ()->url ();
 	}
-	void setHtml (const QString &html) {
-		mainFrame ()->setHtml (html);
+	void setHtmlWrapper(const QString &html, const QUrl &baseurl) {
+		direct_load = true;
+		mainFrame()->setHtml(html, baseurl);
 	}
 	QPointF scrollPosition () const {
 		return mainFrame ()->scrollPosition ();
@@ -127,6 +128,10 @@ class RKWebPage : public QWebEnginePage { (public)
 		});
 	}
 #else
+	void setHtmlWrapper(const QString &html, const QUrl &baseurl) {
+		direct_load = true;
+		setHtml(html, baseurl);
+	}
 	bool supportsContentType (const QString &name) {
 		if (name.startsWith("text")) return true;
 #ifdef __GNUC__
@@ -617,7 +622,7 @@ bool RKHTMLWindow::openURL (const QUrl &url) {
 				RK_DEBUG (APP, DL_WARNING, "Applying workaround for https://bugs.kde.org/show_bug.cgi?id=405386");
 				QFile f (url.toLocalFile ());
 				f.open (QIODevice::ReadOnly);
-				page->setHtml (f.readAll());
+				page->setHtmlWrapper(f.readAll(), url.adjusted(QUrl::RemoveFilename));
 				f.close ();
 			} else {
 				page->load (url);
