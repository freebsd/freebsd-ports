--- test/gtest/ucs/test_profile.cc.orig	2026-02-04 09:52:47 UTC
+++ test/gtest/ucs/test_profile.cc
@@ -13,6 +13,7 @@ extern "C" {
 #include <ucp/api/ucp.h>
 }
 
+#include <libgen.h>
 #include <pthread.h>
 #include <fstream>
 
@@ -235,7 +236,8 @@ void test_profile::test_locations(const ucs_profile_lo
     std::set<std::string> loc_names;
     for (unsigned i = 0; i < num_locations; ++i) {
         const ucs_profile_location_t *loc = &locations[i];
-        EXPECT_EQ(std::string(basename(__FILE__)), std::string(loc->file));
+        char file_copy[] = __FILE__;
+        EXPECT_EQ(std::string(basename(file_copy)), std::string(loc->file));
         EXPECT_GE(loc->line, MIN_LINE);
         EXPECT_LE(loc->line, MAX_LINE);
         loc_names.insert(loc->name);
