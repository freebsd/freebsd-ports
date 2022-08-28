--- testscpp/test_main.cpp.orig	2022-08-27 22:08:08 UTC
+++ testscpp/test_main.cpp
@@ -1,5 +1,5 @@
 #define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
-#include "Catch2/single_include/catch2/catch.hpp"
+#include <catch2/catch.hpp>
 
 /*
 The purpose of this file is to include Catch's main(). Tests can be found inside tests directory.
