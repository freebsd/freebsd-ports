--- content/browser/webui/web_ui_impl.cc.orig	2018-07-19 22:41:18.526274000 +0200
+++ content/browser/webui/web_ui_impl.cc	2018-07-19 22:50:47.735965000 +0200
@@ -247,9 +247,9 @@
   ExecuteJavascript(GetJavascriptCall(function_name, args));
 }
 
-void WebUIImpl::RegisterMessageCallback(base::StringPiece message,
+void WebUIImpl::RegisterMessageCallback(const std::string &message,
                                         const MessageCallback& callback) {
-  message_callbacks_.emplace(message, callback);
+  message_callbacks_.insert(std::make_pair(message, callback));
 }
 
 void WebUIImpl::ProcessWebUIMessage(const GURL& source_url,
