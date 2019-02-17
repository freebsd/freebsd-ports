As long as we ship QtWebEngine 5.9 with a newer rest-of-Qt,
basing checks on the Qt version for deciding what QtWebEngine
features to use is going to break.

Hit the code with a hammer. When QtWebEngine 5.12 lands, remove this patch.

--- src/lib/webengine/webview.cpp.orig	2018-05-08 14:18:50 UTC
+++ src/lib/webengine/webview.cpp
@@ -495,7 +495,8 @@ void WebView::copyLinkToClipboard()
 
 void WebView::savePageAs()
 {
-#if QT_VERSION >= QT_VERSION_CHECK(5, 10, 0)
+#if 0
+// #if QT_VERSION >= QT_VERSION_CHECK(5, 10, 0)
     page()->runJavaScript(QSL("document.contentType"), WebPage::SafeJsWorld, [this](const QVariant &res) {
         const QSet<QString> webPageTypes = {
             QSL("text/html"),
