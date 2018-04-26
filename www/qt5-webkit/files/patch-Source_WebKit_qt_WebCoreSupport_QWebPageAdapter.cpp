Fix crash in QWebPage::selectedHtml() when selectedRange is nullptr

obtained from: https://github.com/annulen/webkit/commit/0e75f3272d149bc64899c161f150eb341a2417af

--- Source/WebKit/qt/WebCoreSupport/QWebPageAdapter.cpp.orig	2017-06-09 14:11:36 UTC
+++ Source/WebKit/qt/WebCoreSupport/QWebPageAdapter.cpp
@@ -390,7 +390,10 @@ QString QWebPageAdapter::selectedText() const
 
 QString QWebPageAdapter::selectedHtml() const
 {
-    return page->focusController().focusedOrMainFrame().editor().selectedRange()->toHTML();
+    RefPtr<Range> range = page->focusController().focusedOrMainFrame().editor().selectedRange();
+    if (!range)
+        return QString();
+    return range->toHTML();
 }
 
 bool QWebPageAdapter::isContentEditable() const
