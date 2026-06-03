--- cmake/thirdparty/SetupSmithThirdParty.cmake.orig	2026-03-30 15:30:35.531584000 -0700
+++ cmake/thirdparty/SetupSmithThirdParty.cmake	2026-03-30 15:32:30.484066000 -0700
@@ -54,14 +54,8 @@
     #------------------------------------------------------------------------------
     # Camp
     #------------------------------------------------------------------------------
-    if (NOT CAMP_DIR)
-        message(FATAL_ERROR "CAMP_DIR is required.")
-    endif()
-
-    smith_assert_is_directory(DIR_VARIABLE CAMP_DIR)
+    find_dependency(camp REQUIRED)
 
-    find_dependency(camp REQUIRED PATHS "${CAMP_DIR}")
-
     smith_assert_find_succeeded(PROJECT_NAME Camp
                                 TARGET       camp
                                 DIR_VARIABLE CAMP_DIR)
