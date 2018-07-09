--- cmake_support/CopyDependencies.cmake.orig	2018-07-09 02:47:08 UTC
+++ cmake_support/CopyDependencies.cmake
@@ -996,10 +996,10 @@ function(copy_python include_path versio
     endforeach()
   else()
     file(COPY ${python_root_dir}/${LIB_DIR}/python${version}/ DESTINATION ${CMAKE_INSTALL_PREFIX}/${LIB_DIR}/python${version} PATTERN "*.pyc" EXCLUDE)
-    if("${LIB_DIR}" MATCHES "lib64")
+    if("${LIB_DIR}" MATCHES "lib")
       # for 64 bit systems we have to copy the python dir within lib in addition as norarch site packages might get installed there
       file(COPY ${python_root_dir}/lib/python${version}/ DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/python${version} PATTERN "*.pyc" EXCLUDE)
-    endif("${LIB_DIR}" MATCHES "lib64")
+    endif("${LIB_DIR}" MATCHES "lib")
   endif()
   file(GLOB  py_config_files "${include_path}/pyconfig*.h")
   file(COPY ${py_config_files} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/python${version})
