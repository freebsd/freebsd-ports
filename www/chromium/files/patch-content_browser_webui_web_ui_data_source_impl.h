--- content/browser/webui/web_ui_data_source_impl.h.orig	2019-01-09 19:45:44.740357000 +0100
+++ content/browser/webui/web_ui_data_source_impl.h	2019-01-09 19:48:21.066890000 +0100
@@ -31,15 +31,15 @@
                                            public WebUIDataSource {
  public:
   // WebUIDataSource implementation:
-  void AddString(base::StringPiece name, const base::string16& value) override;
-  void AddString(base::StringPiece name, const std::string& value) override;
-  void AddLocalizedString(base::StringPiece name, int ids) override;
+  void AddString(const std::string& name, const base::string16& value) override;
+  void AddString(const std::string& name, const std::string& value) override;
+  void AddLocalizedString(const std::string& name, int ids) override;
   void AddLocalizedStrings(
       const base::DictionaryValue& localized_strings) override;
-  void AddBoolean(base::StringPiece name, bool value) override;
-  void AddInteger(base::StringPiece name, int32_t value) override;
-  void SetJsonPath(base::StringPiece path) override;
-  void AddResourcePath(base::StringPiece path, int resource_id) override;
+  void AddBoolean(const std::string& name, bool value) override;
+  void AddInteger(const std::string& name, int32_t value) override;
+  void SetJsonPath(const std::string& path) override;
+  void AddResourcePath(const std::string& path, int resource_id) override;
   void SetDefaultResource(int resource_id) override;
   void SetRequestFilter(
       const WebUIDataSource::HandleRequestCallback& callback) override;
