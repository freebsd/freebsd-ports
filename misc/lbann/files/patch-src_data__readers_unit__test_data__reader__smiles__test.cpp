-- The "pb" namespace alias conflicts with the internal "pb" namespace used
-- by newer versions of protobuf, and google/protobuf/stubs/logging.h has
-- been removed. Use the fully-qualified google::protobuf namespace and
-- drop the now-removed LogSilencer calls so the unit tests build against
-- the protobuf version available in the Ports tree.

--- src/data_readers/unit_test/data_reader_smiles_test.cpp.orig	2026-08-01 17:40:25 UTC
+++ src/data_readers/unit_test/data_reader_smiles_test.cpp
@@ -35,7 +35,6 @@
 // The code being tested
 #include "lbann/data_readers/data_reader_smiles.hpp"
 
-namespace pb = ::google::protobuf;
 
 TEST_CASE("SMILES string encoder", "[data_reader][smiles]")
 {
