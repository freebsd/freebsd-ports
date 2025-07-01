--- tensorflow/tools/proto_text/gen_proto_text_functions.cc.orig	2023-09-12 16:46:28 UTC
+++ tensorflow/tools/proto_text/gen_proto_text_functions.cc
@@ -31,8 +31,8 @@ class CrashOnErrorCollector
  public:
   ~CrashOnErrorCollector() override {}
 
-  void AddError(const string& filename, int line, int column,
-                const string& message) override {
+  void RecordError(absl::string_view filename, int line, int column,
+                   absl::string_view message) override {
     LOG(FATAL) << "Unexpected error at " << filename << "@" << line << ":"
                << column << " - " << message;
   }
