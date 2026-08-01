-- The "pb" namespace alias conflicts with the internal "pb" namespace used
-- by newer versions of protobuf, and google/protobuf/stubs/logging.h has
-- been removed. Use the fully-qualified google::protobuf namespace and
-- drop the now-removed LogSilencer calls so the unit tests build against
-- the protobuf version available in the Ports tree.

--- src/models/unit_test/modify_test.cpp.orig	2026-08-01 17:40:25 UTC
+++ src/models/unit_test/modify_test.cpp
@@ -41,7 +41,6 @@ using namespace lbann;
 
 using namespace lbann;
 
-namespace pb = ::google::protobuf;
 
 namespace {
 // model_prototext string is defined here as a "const std::string".
@@ -50,7 +49,7 @@ auto make_model(lbann::lbann_comm& comm)
 auto make_model(lbann::lbann_comm& comm)
 {
   lbann_data::LbannPB my_proto;
-  if (!pb::TextFormat::ParseFromString(model_prototext, &my_proto))
+  if (!google::protobuf::TextFormat::ParseFromString(model_prototext, &my_proto))
     throw "Parsing protobuf failed.";
   // Construct a trainer so that the model can register the input layer
   auto& trainer =
