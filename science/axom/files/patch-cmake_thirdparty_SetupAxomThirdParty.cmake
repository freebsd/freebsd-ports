--- cmake/thirdparty/SetupAxomThirdParty.cmake.orig	2026-10-04 19:14:49 UTC
+++ cmake/thirdparty/SetupAxomThirdParty.cmake
@@ -31,13 +31,8 @@ endif()
 #------------------------------------------------------------------------------
 # Camp (needed by RAJA and Umpire)
 #------------------------------------------------------------------------------
-if ((RAJA_DIR OR UMPIRE_DIR) AND NOT CAMP_DIR)
-    message(FATAL_ERROR "CAMP_DIR is required if RAJA_DIR or UMPIRE_DIR is provided.")
-endif()
-
-if(CAMP_DIR)
-    axom_assert_is_directory(DIR_VARIABLE CAMP_DIR)
-    find_dependency(camp REQUIRED PATHS "${CAMP_DIR}" NO_SYSTEM_ENVIRONMENT_PATH)
+if(TRUE)
+    find_package(camp REQUIRED)
     axom_assert_find_succeeded(PROJECT_NAME Camp
                                TARGET       camp
                                DIR_VARIABLE CAMP_DIR)
@@ -49,9 +44,8 @@ endif()
 #------------------------------------------------------------------------------
 # UMPIRE
 #------------------------------------------------------------------------------
-if (UMPIRE_DIR)
-    axom_assert_is_directory(DIR_VARIABLE UMPIRE_DIR)
-    find_dependency(umpire REQUIRED PATHS "${UMPIRE_DIR}" NO_SYSTEM_ENVIRONMENT_PATH)
+if (TRUE)
+    find_package(umpire REQUIRED)
     axom_assert_find_succeeded(PROJECT_NAME Umpire
                                TARGET       umpire::umpire
                                DIR_VARIABLE UMPIRE_DIR)
@@ -105,9 +99,8 @@ endif()
 #------------------------------------------------------------------------------
 # RAJA
 #------------------------------------------------------------------------------
-if (RAJA_DIR)
-    axom_assert_is_directory(DIR_VARIABLE RAJA_DIR)
-    find_dependency(raja REQUIRED PATHS "${RAJA_DIR}" NO_SYSTEM_ENVIRONMENT_PATH)
+if (TRUE)
+    find_package(raja REQUIRED)
     axom_assert_find_succeeded(PROJECT_NAME RAJA
                                TARGET       RAJA
                                DIR_VARIABLE RAJA_DIR)
