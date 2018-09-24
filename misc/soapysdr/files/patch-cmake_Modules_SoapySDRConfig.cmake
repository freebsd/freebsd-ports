--- cmake/Modules/SoapySDRConfig.cmake.orig	2018-09-24 13:58:55 UTC
+++ cmake/Modules/SoapySDRConfig.cmake
@@ -110,10 +110,6 @@ if(MSVC)
     add_definitions(-DNOMINMAX) #enables std::min and std::max
 endif()
 
-if ("${CMAKE_SYSTEM_NAME}" STREQUAL "FreeBSD")
-    add_compile_options(-stdlib=libc++)
-endif()
-
 ########################################################################
 # extract the ABI version string from the Version.h header
 ########################################################################
