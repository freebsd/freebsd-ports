--- ./cmake/Modules/DefineCompilerFlags.cmake.orig	2013-09-04 11:15:42.000000000 +0200
+++ ./cmake/Modules/DefineCompilerFlags.cmake	2013-09-18 16:29:48.000000000 +0200
@@ -30,11 +30,6 @@
         set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
     endif (WITH_FPIC AND NOT WIN32)
 
-    check_c_compiler_flag_ssp("-fstack-protector" WITH_STACK_PROTECTOR)
-    if (WITH_STACK_PROTECTOR AND NOT WIN32)
-        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fstack-protector")
-    endif (WITH_STACK_PROTECTOR AND NOT WIN32)
-
     if (WITH_OPTIMIZATION)
     check_c_compiler_flag("-D_FORTIFY_SOURCE=2" WITH_FORTIFY_SOURCE)
         if (WITH_FORTIFY_SOURCE)
