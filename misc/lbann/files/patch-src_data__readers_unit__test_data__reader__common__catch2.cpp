-- The "pb" namespace alias conflicts with the internal "pb" namespace used
-- by newer versions of protobuf. Use the fully-qualified google::protobuf
-- namespace so the unit tests build against the protobuf version available
-- in the Ports tree.

--- src/data_readers/unit_test/data_reader_common_catch2.cpp.orig	2026-08-01 17:43:19 UTC
+++ src/data_readers/unit_test/data_reader_common_catch2.cpp
@@ -57,7 +57,7 @@ instantiate_data_readers(std::string prototext_in,
                          lbann::generic_data_reader*& tournament_ptr)
 {
   lbann_data::LbannPB my_proto;
-  if (!pb::TextFormat::ParseFromString(prototext_in, &my_proto)) {
+  if (!google::protobuf::TextFormat::ParseFromString(prototext_in, &my_proto)) {
     throw "Parsing protobuf failed.";
   }
 
