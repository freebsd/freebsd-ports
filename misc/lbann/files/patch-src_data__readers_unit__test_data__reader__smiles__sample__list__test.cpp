-- The "pb" namespace alias conflicts with the internal "pb" namespace used
-- by newer versions of protobuf, and google/protobuf/stubs/logging.h has
-- been removed. Use the fully-qualified google::protobuf namespace and
-- drop the now-removed LogSilencer calls so the unit tests build against
-- the protobuf version available in the Ports tree.

--- src/data_readers/unit_test/data_reader_smiles_sample_list_test.cpp.orig	2026-08-01 17:40:25 UTC
+++ src/data_readers/unit_test/data_reader_smiles_sample_list_test.cpp
@@ -38,7 +38,6 @@
 #include "lbann/data_readers/sample_list_impl.hpp"
 #include "lbann/data_readers/sample_list_open_files_impl.hpp"
 
-namespace pb = ::google::protobuf;
 
 namespace {
 
