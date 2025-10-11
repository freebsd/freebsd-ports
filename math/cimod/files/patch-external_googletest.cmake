--- external/googletest.cmake.orig	2025-01-27 12:00:00 UTC
+++ external/googletest.cmake
@@ -14,38 +14,11 @@
 
 include(FetchContent)
 
-message(CHECK_START "Fetching GoogleTest")
-list(APPEND CMAKE_MESSAGE_INDENT "  ")
-
-set(CMAKE_CXX_STANDARD 17)
-set(FETCHCONTENT_QUIET OFF)
-
-#### Google test ####
-FetchContent_Declare(
-    googletest
-    GIT_REPOSITORY  https://github.com/google/googletest
-    GIT_TAG         v1.17.0
-    GIT_SHALLOW     TRUE
-)
-
-if(WIN32)
-  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
-endif()
-
-# Prevent googletest from being installed by using FetchContent_Populate + add_subdirectory with EXCLUDE_FROM_ALL
-FetchContent_GetProperties(googletest)
-if(NOT googletest_POPULATED)
-    FetchContent_Populate(googletest)
-    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)
-endif()
-
+# Try to find pre-installed GoogleTest first
 find_package(GTest)
 
-#FetchContent_GetProperties(googletest)
-
-#message(STATUS "gtest_SOURCE_DIR = ${gtest_SOURCE_DIR}")
-#message(STATUS "gmock_SOURCE_DIR = ${gmock_SOURCE_DIR}")
-
-
-list(POP_BACK CMAKE_MESSAGE_INDENT)
-message(CHECK_PASS "fetched")
+if(NOT GTest_FOUND)
+    message(FATAL_ERROR "GoogleTest not found. Please install googletest package.")
+else()
+    message(STATUS "Found pre-installed GoogleTest")
+endif()
