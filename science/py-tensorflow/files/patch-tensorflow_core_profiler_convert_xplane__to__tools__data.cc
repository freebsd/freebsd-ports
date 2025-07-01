--- tensorflow/core/profiler/convert/xplane_to_tools_data.cc.orig	2023-09-12 16:46:28 UTC
+++ tensorflow/core/profiler/convert/xplane_to_tools_data.cc
@@ -147,7 +147,7 @@ StatusOr<std::string> ConvertMultiXSpacesToPodViewer(
 
   std::string json_output;
   protobuf::util::JsonPrintOptions opts;
-  opts.always_print_primitive_fields = true;
+  opts.always_print_fields_with_no_presence = true;
   auto encode_status = protobuf::util::MessageToJsonString(
       ConvertOpStatsToPodViewer(combined_op_stats), &json_output, opts);
   if (!encode_status.ok()) {
@@ -201,7 +201,7 @@ StatusOr<std::string> ConvertMultiXSpacesToOpProfileVi
       profile);
   std::string json_output;
   protobuf::util::JsonPrintOptions opts;
-  opts.always_print_primitive_fields = true;
+  opts.always_print_fields_with_no_presence = true;
 
   auto encode_status =
       protobuf::util::MessageToJsonString(profile, &json_output, opts);
