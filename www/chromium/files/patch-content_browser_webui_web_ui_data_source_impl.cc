--- content/browser/webui/web_ui_data_source_impl.cc.orig	2019-01-09 19:45:36.420732000 +0100
+++ content/browser/webui/web_ui_data_source_impl.cc	2019-01-09 19:53:12.218574000 +0100
@@ -123,24 +123,24 @@
 WebUIDataSourceImpl::~WebUIDataSourceImpl() {
 }
 
-void WebUIDataSourceImpl::AddString(base::StringPiece name,
+void WebUIDataSourceImpl::AddString(const std::string& name,
                                     const base::string16& value) {
   // TODO(dschuyler): Share only one copy of these strings.
   localized_strings_.SetKey(name, base::Value(value));
-  replacements_[name.as_string()] = base::UTF16ToUTF8(value);
+  replacements_[name] = base::UTF16ToUTF8(value);
 }
 
-void WebUIDataSourceImpl::AddString(base::StringPiece name,
+void WebUIDataSourceImpl::AddString(const std::string& name,
                                     const std::string& value) {
   localized_strings_.SetKey(name, base::Value(value));
-  replacements_[name.as_string()] = value;
+  replacements_[name] = value;
 }
 
-void WebUIDataSourceImpl::AddLocalizedString(base::StringPiece name, int ids) {
+void WebUIDataSourceImpl::AddLocalizedString(const std::string& name, int ids) {
   std::string utf8_str =
       base::UTF16ToUTF8(GetContentClient()->GetLocalizedString(ids));
   localized_strings_.SetKey(name, base::Value(utf8_str));
-  replacements_[name.as_string()] = utf8_str;
+  replacements_[name] = utf8_str;
 }
 
 void WebUIDataSourceImpl::AddLocalizedStrings(
@@ -150,7 +150,7 @@
                                               &replacements_);
 }
 
-void WebUIDataSourceImpl::AddBoolean(base::StringPiece name, bool value) {
+void WebUIDataSourceImpl::AddBoolean(const std::string& name, bool value) {
   localized_strings_.SetBoolean(name, value);
   // TODO(dschuyler): Change name of |localized_strings_| to |load_time_data_|
   // or similar. These values haven't been found as strings for
@@ -159,21 +159,21 @@
   // replacements.
 }
 
-void WebUIDataSourceImpl::AddInteger(base::StringPiece name, int32_t value) {
+void WebUIDataSourceImpl::AddInteger(const std::string& name, int32_t value) {
   localized_strings_.SetInteger(name, value);
 }
 
-void WebUIDataSourceImpl::SetJsonPath(base::StringPiece path) {
+void WebUIDataSourceImpl::SetJsonPath(const std::string& path) {
   DCHECK(json_path_.empty());
   DCHECK(!path.empty());
 
-  json_path_ = path.as_string();
+  json_path_ = path;
   excluded_paths_.insert(json_path_);
 }
 
-void WebUIDataSourceImpl::AddResourcePath(base::StringPiece path,
+void WebUIDataSourceImpl::AddResourcePath(const std::string& path,
                                           int resource_id) {
-  path_to_idr_map_[path.as_string()] = resource_id;
+  path_to_idr_map_[path] = resource_id;
 }
 
 void WebUIDataSourceImpl::SetDefaultResource(int resource_id) {
