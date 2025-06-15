--- test/test_solvers.cpp.orig	2025-01-05 22:29:55 UTC
+++ test/test_solvers.cpp
@@ -29,7 +29,13 @@
 #include <boost/iostreams/filter/gzip.hpp>
 #include <boost/filesystem.hpp>
 #include <boost/random/random_device.hpp>
+#if BOOST_VERSION >= 108800 // v2 is now default
+#define BOOST_PROCESS_VERSION 1
+#include <boost/process/v1/io.hpp>
+#include <boost/process/v1/system.hpp>
+#else
 #include <boost/process.hpp>
+#endif
 
 #include "tools/cxxopts.hpp"
 #include "oink/oink.hpp"
