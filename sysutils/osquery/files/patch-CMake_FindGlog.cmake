--- CMake/FindGlog.cmake.orig	2015-05-05 00:16:41 UTC
+++ CMake/FindGlog.cmake
@@ -6,20 +6,6 @@ endif()
 set(GLOG_ROOT_DIR "${CMAKE_BINARY_DIR}/third-party/glog")
 set(GLOG_SOURCE_DIR "${CMAKE_SOURCE_DIR}/third-party/glog")
 
-if(NOT APPLE)
-  include(CheckIncludeFiles)
-  unset(LIBUNWIND_FOUND CACHE)
-  check_include_files("libunwind.h;unwind.h" LIBUNWIND_FOUND)
-  if(LIBUNWIND_FOUND)
-    unset(libglog_FOUND CACHE)
-    execute_process(
-      COMMAND rm -rf "${GLOG_ROOT_DIR}" "${CMAKE_BINARY_DIR}/libglog-prefix"
-      ERROR_QUIET
-    )
-    message(WARNING "${Esc}[31mWarning: libunwind headers found [Issue #596], please: make deps\n${Esc}[m")
-  endif()
-endif()
-
 set(GLOG_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-register -Wno-unnamed-type-template-args -Wno-deprecated -Wno-error")
 
 INCLUDE(ExternalProject)
@@ -31,8 +17,8 @@ ExternalProject_Add(
     CC=${CMAKE_C_COMPILER} CXX=${CMAKE_CXX_COMPILER}
     CXXFLAGS=${GLOG_CXX_FLAGS}
     --enable-frame-pointers --enable-shared=no --prefix=${GLOG_ROOT_DIR}
-  BUILD_COMMAND make
-  INSTALL_COMMAND make install
+  BUILD_COMMAND ${CMAKE_MAKE_PROGRAM}
+  INSTALL_COMMAND ${CMAKE_MAKE_PROGRAM} install
   LOG_CONFIGURE ON
   LOG_INSTALL ON
   LOG_BUILD ON
