--- src/3rdparty/chromium/content/browser/webui/web_ui_impl.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/content/browser/webui/web_ui_impl.cc
@@ -249,9 +249,9 @@ void WebUIImpl::CallJavascriptFunctionUnsafe(
   ExecuteJavascript(GetJavascriptCall(function_name, args));
 }
 
-void WebUIImpl::RegisterMessageCallback(base::StringPiece message,
+void WebUIImpl::RegisterMessageCallback(const std::string& message,
                                         const MessageCallback& callback) {
-  message_callbacks_.emplace(message.as_string(), callback);
+  message_callbacks_.insert(std::make_pair(message, callback));
 }
 
 void WebUIImpl::ProcessWebUIMessage(const GURL& source_url,
