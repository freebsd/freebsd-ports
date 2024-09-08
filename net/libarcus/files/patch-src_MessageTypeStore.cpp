--- src/MessageTypeStore.cpp.orig	2023-05-19 06:44:12 UTC
+++ src/MessageTypeStore.cpp
@@ -39,7 +39,7 @@ class ErrorCollector : public google::protobuf::compil
     {
     }
 
-    void AddError(const std::string& filename, int line, int column, const std::string& message) override
+    void AddError(const std::string& filename, int line, int column, const std::string& message)
     {
         _stream << "[" << filename << " (" << line << "," << column << ")] " << message << std::endl;
         _error_count++;
@@ -53,6 +53,10 @@ class ErrorCollector : public google::protobuf::compil
     int getErrorCount()
     {
         return _error_count;
+    }
+
+    void RecordError(absl::string_view filename, int line, int column, absl::string_view message)
+    {
     }
 
 private:
