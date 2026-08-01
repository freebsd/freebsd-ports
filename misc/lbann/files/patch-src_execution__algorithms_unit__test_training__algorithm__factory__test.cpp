-- The "pb" namespace alias conflicts with the internal "pb" namespace used
-- by newer versions of protobuf, and google/protobuf/stubs/logging.h has
-- been removed. Use the fully-qualified google::protobuf namespace and
-- drop the now-removed LogSilencer calls so the unit tests build against
-- the protobuf version available in the Ports tree.

--- src/execution_algorithms/unit_test/training_algorithm_factory_test.cpp.orig	2026-08-01 17:40:25 UTC
+++ src/execution_algorithms/unit_test/training_algorithm_factory_test.cpp
@@ -31,14 +31,12 @@
 #include "lbann/utils/make_abstract.hpp"
 
 #include <exception>
-#include <google/protobuf/stubs/logging.h>
 #include <lbann/execution_algorithms/factory.hpp>
 
 #include "lbann/proto/training_algorithm.pb.h"
 
 #include <google/protobuf/text_format.h>
 
-namespace pb = ::google::protobuf;
 
 #ifdef LBANN_USE_CATCH2_V3
 static Catch::Matchers::StringContainsMatcher Contains(std::string const& str)
@@ -62,7 +60,7 @@ parameters {
 })proto";
 
     lbann_data::TrainingAlgorithm algo_msg;
-    REQUIRE(pb::TextFormat::ParseFromString(valid_prototext, &algo_msg));
+    REQUIRE(google::protobuf::TextFormat::ParseFromString(valid_prototext, &algo_msg));
     REQUIRE(algo_msg.has_parameters());
     REQUIRE(algo_msg.parameters().Is<lbann_data::SGD>());
     REQUIRE(algo_msg.name() == "local sgd");
@@ -87,11 +85,10 @@ parameters {
     // Protobuf will log stuff to stderr when errors occur. We know
     // these errors will occur, but they'll add potentially confusing
     // output to the catch run, so we silence them in this section
-    google::protobuf::LogSilencer tmp_silence_pb_logs;
 
     lbann_data::TrainingAlgorithm algo_msg;
     REQUIRE_FALSE(
-      pb::TextFormat::ParseFromString(bad_domain_prototext, &algo_msg));
+      google::protobuf::TextFormat::ParseFromString(bad_domain_prototext, &algo_msg));
   }
   SECTION("Type URL error -- unknown class")
   {
@@ -105,10 +102,9 @@ parameters {
   }
 })proto";
 
-    google::protobuf::LogSilencer tmp_silence_pb_logs;
     lbann_data::TrainingAlgorithm algo_msg;
     REQUIRE_FALSE(
-      pb::TextFormat::ParseFromString(unknown_class_prototext, &algo_msg));
+      google::protobuf::TextFormat::ParseFromString(unknown_class_prototext, &algo_msg));
   }
 
   SECTION("Type URL error -- bad class parameters")
@@ -123,10 +119,9 @@ parameters {
   }
 })proto";
 
-    google::protobuf::LogSilencer tmp_silence_pb_logs;
     lbann_data::TrainingAlgorithm algo_msg;
     REQUIRE_FALSE(
-      pb::TextFormat::ParseFromString(bad_class_prototext, &algo_msg));
+      google::protobuf::TextFormat::ParseFromString(bad_class_prototext, &algo_msg));
   }
 }
 
