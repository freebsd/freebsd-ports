--- cmake/JSSConfig.cmake.orig	2026-07-16 09:37:55 UTC
+++ cmake/JSSConfig.cmake
@@ -196,7 +196,6 @@ macro(jss_config_ldflags)
     list(APPEND JSS_LD_FLAGS "-lplds4")
     list(APPEND JSS_LD_FLAGS "-lnspr4")
     list(APPEND JSS_LD_FLAGS "-lpthread")
-    list(APPEND JSS_LD_FLAGS "-ldl")
 
     separate_arguments(PASSED_LD_FLAGS UNIX_COMMAND "${CMAKE_SHARED_LINKER_FLAGS}")
     foreach(PASSED_LD_FLAG ${PASSED_LD_FLAGS})
