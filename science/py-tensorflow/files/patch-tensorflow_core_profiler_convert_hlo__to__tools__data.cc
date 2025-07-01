--- tensorflow/core/profiler/convert/hlo_to_tools_data.cc.orig	2023-09-12 16:46:28 UTC
+++ tensorflow/core/profiler/convert/hlo_to_tools_data.cc
@@ -51,7 +51,7 @@ StatusOr<std::string> ConvertHloProtoToMemoryViewer(
 
   std::string json_output;
   tensorflow::protobuf::util::JsonPrintOptions options;
-  options.always_print_primitive_fields = true;
+  options.always_print_fields_with_no_presence = true;
   auto encoded_status = tensorflow::protobuf::util::MessageToJsonString(
       result_or.value(), &json_output, options);
   if (!encoded_status.ok()) {
