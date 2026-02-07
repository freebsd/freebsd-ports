--- tensorflow/tsl/platform/default/human_readable_json.cc.orig	2023-09-12 16:46:28 UTC
+++ tensorflow/tsl/platform/default/human_readable_json.cc
@@ -27,7 +27,7 @@ Status ProtoToHumanReadableJson(const protobuf::Messag
 
   protobuf::util::JsonPrintOptions json_options;
   json_options.preserve_proto_field_names = true;
-  json_options.always_print_primitive_fields = true;
+  json_options.always_print_fields_with_no_presence = true;
   auto status =
       protobuf::util::MessageToJsonString(proto, result, json_options);
   if (!status.ok()) {
