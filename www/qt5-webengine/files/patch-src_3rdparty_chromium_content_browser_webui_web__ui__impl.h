--- src/3rdparty/chromium/content/browser/webui/web_ui_impl.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/content/browser/webui/web_ui_impl.h
@@ -52,7 +52,7 @@ class CONTENT_EXPORT WebUIImpl : public WebUI,
   int GetBindings() const override;
   void SetBindings(int bindings) override;
   void AddMessageHandler(std::unique_ptr<WebUIMessageHandler> handler) override;
-  void RegisterMessageCallback(base::StringPiece message,
+  void RegisterMessageCallback(const std::string& message,
                                const MessageCallback& callback) override;
   void ProcessWebUIMessage(const GURL& source_url,
                            const std::string& message,
