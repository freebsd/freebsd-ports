--- tensorflow/compiler/mlir/lite/python/jax_to_tfl_flatbuffer.cc.orig	2023-09-12 16:46:28 UTC
+++ tensorflow/compiler/mlir/lite/python/jax_to_tfl_flatbuffer.cc
@@ -60,7 +60,7 @@ class NoOpErrorCollector : public tensorflow::protobuf
 // Error collector that simply ignores errors reported.
 class NoOpErrorCollector : public tensorflow::protobuf::io::ErrorCollector {
  public:
-  void AddError(int line, int column, const string& message) override {}
+  void RecordError(int line, int column, absl::string_view message) override {}
 };
 
 bool LoadHloProto(const std::string& contents, xla::HloProto* hlo_proto) {
