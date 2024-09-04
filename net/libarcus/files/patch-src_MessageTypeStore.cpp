--- src/MessageTypeStore.cpp.orig	2024-08-19 14:31:10.714537000 +0200
+++ src/MessageTypeStore.cpp	2024-08-19 15:30:50.769879000 +0200
@@ -39,7 +39,7 @@
     {
     }
 
-    void AddError(const std::string& filename, int line, int column, const std::string& message) override
+    void AddError(const std::string& filename, int line, int column, const std::string& message)
     {
         _stream << "[" << filename << " (" << line << "," << column << ")] " << message << std::endl;
         _error_count++;
@@ -53,6 +53,10 @@
     int getErrorCount()
     {
         return _error_count;
+    }
+
+    void RecordError(absl::string_view filename, int line, int column, absl::string_view message)
+    {
     }
 
 private:
