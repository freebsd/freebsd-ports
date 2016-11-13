--- libaegisub/include/libaegisub/file_mapping.h.orig	2014-12-08 00:07:09 UTC
+++ libaegisub/include/libaegisub/file_mapping.h
@@ -18,6 +18,7 @@
 
 #include <boost/interprocess/detail/os_file_functions.hpp>
 #include <cstdint>
+#include <memory> // std::unique_ptr
 
 namespace agi {
 	// boost::interprocess::file_mapping is awesome and uses CreateFileA on Windows
