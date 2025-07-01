--- tensorflow/core/util/proto/proto_utils.h.orig	2023-09-12 16:46:28 UTC
+++ tensorflow/core/util/proto/proto_utils.h
@@ -52,11 +52,11 @@ class StringErrorCollector : public protobuf::io::Erro
   StringErrorCollector(const StringErrorCollector&) = delete;
   StringErrorCollector& operator=(const StringErrorCollector&) = delete;
 
-  // Implementation of protobuf::io::ErrorCollector::AddError.
-  void AddError(int line, int column, const string& message) override;
+  // Implementation of protobuf::io::ErrorCollector::RecordError.
+  void RecordError(int line, int column, absl::string_view message) override;
 
-  // Implementation of protobuf::io::ErrorCollector::AddWarning.
-  void AddWarning(int line, int column, const string& message) override;
+  // Implementation of protobuf::io::ErrorCollector::RecordWarning.
+  void RecordWarning(int line, int column, absl::string_view message) override;
 
  private:
   string* const error_text_;
