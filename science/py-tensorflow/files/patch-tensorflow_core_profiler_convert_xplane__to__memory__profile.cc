--- tensorflow/core/profiler/convert/xplane_to_memory_profile.cc.orig	2023-09-12 16:46:28 UTC
+++ tensorflow/core/profiler/convert/xplane_to_memory_profile.cc
@@ -529,7 +529,7 @@ Status ConvertProtoToJson(const Proto& proto_output, s
 template <typename Proto>
 Status ConvertProtoToJson(const Proto& proto_output, std::string* json_output) {
   protobuf::util::JsonPrintOptions json_options;
-  json_options.always_print_primitive_fields = true;
+  json_options.always_print_fields_with_no_presence = true;
   auto status = protobuf::util::MessageToJsonString(proto_output, json_output,
                                                     json_options);
   if (!status.ok()) {
