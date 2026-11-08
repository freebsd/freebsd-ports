--- cmake/thirdparty/SetupSmithThirdParty.cmake.orig	2026-09-30 18:18:35 UTC
+++ cmake/thirdparty/SetupSmithThirdParty.cmake
@@ -77,13 +77,7 @@ if (NOT SMITH_THIRD_PARTY_LIBRARIES_FOUND)
     #------------------------------------------------------------------------------
     # Camp
     #------------------------------------------------------------------------------
-    if (NOT CAMP_DIR)
-        message(FATAL_ERROR "CAMP_DIR is required.")
-    endif()
-
-    smith_assert_is_directory(DIR_VARIABLE CAMP_DIR)
-
-    find_dependency(camp REQUIRED PATHS "${CAMP_DIR}")
+    find_dependency(camp REQUIRED)
 
     smith_assert_find_succeeded(PROJECT_NAME Camp
                                 TARGET       camp
