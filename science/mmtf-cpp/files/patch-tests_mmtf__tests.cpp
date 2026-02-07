--- tests/mmtf_tests.cpp.orig	2018-10-18 20:26:48 UTC
+++ tests/mmtf_tests.cpp
@@ -5,7 +5,7 @@
 #define CATCH_CONFIG_MAIN
 #endif
 
-#include "catch.hpp"
+#include <catch2/catch.hpp>
 
 #include <mmtf.hpp>
 #include <mmtf/export_helpers.hpp>
