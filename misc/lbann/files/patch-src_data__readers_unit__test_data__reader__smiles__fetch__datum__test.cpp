-- The "pb" namespace alias conflicts with the internal "pb" namespace used
-- by newer versions of protobuf, and google/protobuf/stubs/logging.h has
-- been removed. Use the fully-qualified google::protobuf namespace and
-- drop the now-removed LogSilencer calls so the unit tests build against
-- the protobuf version available in the Ports tree.

--- src/data_readers/unit_test/data_reader_smiles_fetch_datum_test.cpp.orig	2026-08-01 17:40:25 UTC
+++ src/data_readers/unit_test/data_reader_smiles_fetch_datum_test.cpp
@@ -54,7 +54,6 @@
 #include "test_data/smiles_reader_sample_list.txt"
 #include "test_data/vocab.txt"
 
-namespace pb = ::google::protobuf;
 namespace utils = ::unit_test::utilities;
 using lbann::file::join_path;
 
@@ -107,7 +106,7 @@ TEST_CASE("SMILES functional black-box",
 
   // Parse the data reader prototext
   lbann_data::LbannPB my_proto;
-  REQUIRE(pb::TextFormat::ParseFromString(smiles_reader_prototext, &my_proto));
+  REQUIRE(google::protobuf::TextFormat::ParseFromString(smiles_reader_prototext, &my_proto));
 
   // Instantiate and load the data readers
   std::map<lbann::execution_mode, std::shared_ptr<lbann::generic_data_reader>>
