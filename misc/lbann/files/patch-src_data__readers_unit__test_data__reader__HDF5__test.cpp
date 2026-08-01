-- The "pb" namespace alias conflicts with the internal "pb" namespace used
-- by newer versions of protobuf, and google/protobuf/stubs/logging.h has
-- been removed. Use the fully-qualified google::protobuf namespace and
-- drop the now-removed LogSilencer calls so the unit tests build against
-- the protobuf version available in the Ports tree.

--- src/data_readers/unit_test/data_reader_HDF5_test.cpp.orig	2026-08-01 17:40:25 UTC
+++ src/data_readers/unit_test/data_reader_HDF5_test.cpp
@@ -50,7 +50,6 @@
 #include "./test_data/hdf5_hrrl_validate.sample_list"
 #include "./test_data/hdf5_repack_data_and_schemas.yaml"
 
-namespace pb = ::google::protobuf;
 
 double get_bias_from_node_map(const lbann::hdf5_data_reader* reader,
                               const std::string field_name);
