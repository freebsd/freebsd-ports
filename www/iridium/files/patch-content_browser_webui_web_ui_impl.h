--- content/browser/webui/web_ui_impl.h.orig	2018-07-19 22:41:27.362717000 +0200
+++ content/browser/webui/web_ui_impl.h	2018-07-19 22:51:17.719203000 +0200
@@ -52,7 +52,7 @@
   int GetBindings() const override;
   void SetBindings(int bindings) override;
   void AddMessageHandler(std::unique_ptr<WebUIMessageHandler> handler) override;
-  void RegisterMessageCallback(base::StringPiece message,
+  void RegisterMessageCallback(const std::string& message,
                                const MessageCallback& callback) override;
   void ProcessWebUIMessage(const GURL& source_url,
                            const std::string& message,
