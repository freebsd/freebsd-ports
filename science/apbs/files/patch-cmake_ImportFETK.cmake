-- Patch APBS to build FETK from the already-extracted GH_TUPLE source
-- instead of using CMake FetchContent, which is blocked in the FreeBSD
-- ports sandbox by FETCHCONTENT_FULLY_DISCONNECTED.
--- cmake/ImportFETK.cmake.orig	2026-09-26 18:37:52.230853000 -0700
+++ cmake/ImportFETK.cmake	2026-09-26 18:37:55.974775000 -0700
@@ -39,14 +39,14 @@
 
             # PMG is turned off because of some missing symbols: dc_vec__, dc_scal__, rand_, c_vec__, tsecnd_, and c_scal__
             set(BUILD_PMG OFF)
-        
-            message(STATUS "Building FETK from commit ${FETK_IMPORT_VERSION}")
-            FetchContent_Declare( fetk
-                GIT_REPOSITORY https://github.com/Electrostatics/FETK.git
-                GIT_TAG ${FETK_IMPORT_VERSION}
-            )
-            FetchContent_MakeAvailable( fetk )
 
+            message(STATUS "Building FETK from bundled source at ${EXTERNALS_PATH}/fetk")
+
+            set(fetk_SOURCE_DIR "${EXTERNALS_PATH}/fetk")
+            set(fetk_BINARY_DIR "${CMAKE_BINARY_DIR}/fetk-build")
+            file(MAKE_DIRECTORY ${fetk_BINARY_DIR})
+            add_subdirectory(${fetk_SOURCE_DIR} ${fetk_BINARY_DIR})
+
             list(APPEND CMAKE_MODULE_PATH ${fetk_SOURCE_DIR}/cmake)
 
         endif()
