-- The "pb" namespace alias conflicts with the internal "pb" namespace used
-- by newer versions of protobuf, and google/protobuf/stubs/logging.h has
-- been removed. Use the fully-qualified google::protobuf namespace and
-- drop the now-removed LogSilencer calls so the unit tests build against
-- the protobuf version available in the Ports tree.

--- src/execution_algorithms/unit_test/inference_algorithm_test.cpp.orig	2026-08-01 17:40:25 UTC
+++ src/execution_algorithms/unit_test/inference_algorithm_test.cpp
@@ -38,7 +38,6 @@
 #include "lbann/proto/lbann.pb.h"
 #include <google/protobuf/text_format.h>
 
-namespace pb = ::google::protobuf;
 
 namespace {
 // This model is just an input layer into a softmax layer, so we can verify the
@@ -65,7 +64,7 @@ auto make_model(lbann::lbann_comm& comm, int class_n)
 auto make_model(lbann::lbann_comm& comm, int class_n)
 {
   lbann_data::LbannPB my_proto;
-  if (!pb::TextFormat::ParseFromString(model_prototext, &my_proto))
+  if (!google::protobuf::TextFormat::ParseFromString(model_prototext, &my_proto))
     throw "Parsing protobuf failed.";
   // Construct a trainer so that the model can register the input layer
   auto& trainer =
