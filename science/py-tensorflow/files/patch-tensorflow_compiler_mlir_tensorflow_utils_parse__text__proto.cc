--- tensorflow/compiler/mlir/tensorflow/utils/parse_text_proto.cc.orig	2023-09-12 16:46:28 UTC
+++ tensorflow/compiler/mlir/tensorflow/utils/parse_text_proto.cc
@@ -28,7 +28,7 @@ class NoOpErrorCollector : public protobuf::io::ErrorC
 // Error collector that simply ignores errors reported.
 class NoOpErrorCollector : public protobuf::io::ErrorCollector {
  public:
-  void AddError(int line, int column, const std::string& message) override {}
+  void RecordError(int line, int column, absl::string_view message) override {}
 };
 }  // namespace
 
