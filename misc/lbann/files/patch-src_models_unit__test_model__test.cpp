-- The "pb" namespace alias conflicts with the internal "pb" namespace used
-- by newer versions of protobuf, and google/protobuf/stubs/logging.h has
-- been removed. Use the fully-qualified google::protobuf namespace and
-- drop the now-removed LogSilencer calls so the unit tests build against
-- the protobuf version available in the Ports tree.

--- src/models/unit_test/model_test.cpp.orig	2026-08-01 17:40:25 UTC
+++ src/models/unit_test/model_test.cpp
@@ -42,7 +42,6 @@
 #include "lbann/proto/lbann.pb.h"
 #include <google/protobuf/text_format.h>
 
-namespace pb = ::google::protobuf;
 
 namespace {
 // model_prototext string is defined here as a "const std::string".
@@ -53,7 +52,7 @@ auto make_model(lbann::lbann_comm& comm,
                 const std::string& model_contents = model_prototext)
 {
   lbann_data::LbannPB my_proto;
-  if (!pb::TextFormat::ParseFromString(model_contents, &my_proto))
+  if (!google::protobuf::TextFormat::ParseFromString(model_contents, &my_proto))
     throw "Parsing protobuf failed.";
   // Construct a trainer so that the model can register the input layer
   auto& trainer =
