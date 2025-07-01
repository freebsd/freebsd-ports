--- tensorflow/core/debug/debug_io_utils.cc.orig	2023-09-12 16:46:28 UTC
+++ tensorflow/core/debug/debug_io_utils.cc
@@ -94,7 +94,7 @@ Event PrepareChunkEventProto(const DebugNodeKey& debug
   // Encode the data in JSON.
   string json_output;
   tensorflow::protobuf::util::JsonPrintOptions json_options;
-  json_options.always_print_primitive_fields = true;
+  json_options.always_print_fields_with_no_presence = true;
   auto status = tensorflow::protobuf::util::MessageToJsonString(
       metadata, &json_output, json_options);
   if (status.ok()) {
