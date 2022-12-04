- workaround for https://github.com/LLNL/Silo/issues/288

--- tests/CMake/SiloMakeCheckRunner.cmake.orig	2022-12-03 06:53:38 UTC
+++ tests/CMake/SiloMakeCheckRunner.cmake
@@ -72,7 +72,7 @@ function(silo_add_make_check_runner)
         message(WARNING "silo_add_make_check_runner: NAME argument is required.")
         return()
     endif()
-    set(test_cmd ${samcr_NAME})
+    set(test_cmd "./${samcr_NAME}")
     if("ARGS" IN_LIST samcr_KEYWORDS_MISSING_VALUES)
         message(WARNING "silo_add_make_check_runner: ARGS argument provided without a value.")
         return()
