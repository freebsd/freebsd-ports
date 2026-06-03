--- media_driver/media_top_cmake.cmake.orig	2026-03-19 10:15:05 UTC
+++ media_driver/media_top_cmake.cmake
@@ -32,7 +32,11 @@ include(${MEDIA_DRIVER_CMAKE}/media_feature_flags.cmak
 option (MEDIA_RUN_TEST_SUITE "run google test module after install" ON) 
 include(${MEDIA_DRIVER_CMAKE}/media_gen_flags.cmake)
 include(${MEDIA_DRIVER_CMAKE}/media_feature_flags.cmake)
+include(CheckIncludeFileCXX)
+include(CheckLibraryExists)
 
+check_include_file_cxx("execinfo.h" HAVE_EXECINFO_H)
+check_library_exists(execinfo backtrace "" HAVE_LIBEXECINFO)
 
 if(NOT DEFINED SKIP_GMM_CHECK)
     # checking dependencies
@@ -588,6 +592,13 @@ add_library(${LIB_NAME} SHARED
     $<TARGET_OBJECTS:${LIB_NAME}_SOFTLET_CODEC>
     $<TARGET_OBJECTS:${LIB_NAME}_SOFTLET_COMMON>)
 
+if(HAVE_EXECINFO_H)
+    target_compile_definitions(${LIB_NAME} PRIVATE HAVE_EXECINFO_H)
+endif()
+
+if(HAVE_LIBEXECINFO)
+    target_link_libraries (${LIB_NAME} execinfo)
+endif()
 
 add_library(${LIB_NAME_STATIC} STATIC
     $<TARGET_OBJECTS:${LIB_NAME}_mos>
