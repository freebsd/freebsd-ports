--- cmake/Modules/11DefineCompilerFlags.cmake	2013-12-17 11:05:41.000000000 +0400
+++ cmake/Modules/DefineCompilerFlags.cmake	2013-12-17 11:06:00.579967195 +0400
@@ -30,11 +30,6 @@
         set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
     endif (WITH_FPIC AND NOT WIN32)
 
-    check_c_compiler_flag_ssp("-fstack-protector" WITH_STACK_PROTECTOR)
-    if (WITH_STACK_PROTECTOR AND NOT WIN32)
-        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fstack-protector")
-    endif (WITH_STACK_PROTECTOR AND NOT WIN32)
-
     if (CMAKE_BUILD_TYPE)
         string(TOLOWER "${CMAKE_BUILD_TYPE}" CMAKE_BUILD_TYPE_LOWER)
         if (CMAKE_BUILD_TYPE_LOWER MATCHES "(release|relwithdebinfo|minsizerel)")
