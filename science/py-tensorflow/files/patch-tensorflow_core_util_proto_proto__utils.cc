--- tensorflow/core/util/proto/proto_utils.cc.orig	2023-09-12 16:46:28 UTC
+++ tensorflow/core/util/proto/proto_utils.cc
@@ -101,17 +101,17 @@ StringErrorCollector::StringErrorCollector(string* err
   }
 }
 
-void StringErrorCollector::AddError(int line, int column,
-                                    const string& message) {
+void StringErrorCollector::RecordError(int line, int column,
+                                       absl::string_view message) {
   if (error_text_ != nullptr) {
     absl::SubstituteAndAppend(error_text_, "$0($1): $2\n", line + index_offset_,
                               column + index_offset_, message);
   }
 }
 
-void StringErrorCollector::AddWarning(int line, int column,
-                                      const string& message) {
-  AddError(line, column, message);
+void StringErrorCollector::RecordWarning(int line, int column,
+                                         absl::string_view message) {
+  RecordError(line, column, message);
 }
 
 }  // namespace proto_utils
