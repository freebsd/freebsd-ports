-- The "pb" namespace alias conflicts with the internal "pb" namespace used
-- by newer versions of protobuf, and google/protobuf/stubs/logging.h has
-- been removed. Use the fully-qualified google::protobuf namespace and
-- drop the now-removed LogSilencer calls so the unit tests build against
-- the protobuf version available in the Ports tree.

--- src/data_readers/unit_test/data_reader_common_catch2.hpp.orig	2026-08-01 17:40:25 UTC
+++ src/data_readers/unit_test/data_reader_common_catch2.hpp
@@ -36,7 +36,6 @@
 
 #include "lbann/proto/lbann.pb.h"
 #include <google/protobuf/text_format.h>
-namespace pb = ::google::protobuf;
 
 /** create a directory in /tmp; returns the pathname to the directory */
 std::string create_test_directory(std::string base_name);
