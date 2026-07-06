-- On FreeBSD, system OpenBLAS headers reside in /usr/local/include alongside
-- other system packages (including a newer protobuf). Using include_directories()
-- without SYSTEM makes it a regular -I path, which is searched BEFORE any
-- target_include_directories() entries such as the bundled protobuf headers.
-- Using SYSTEM causes cmake to emit -isystem instead of -I, which the compiler
-- always searches AFTER all user (-I) include directories, preventing the newer
-- system protobuf headers from shadowing the bundled protobuf 3.21.12 headers.
--- cmake/cblas.cmake.orig	2026-06-19 21:52:38 UTC
+++ cmake/cblas.cmake
@@ -190,7 +190,11 @@ endif()
 # FIXME(gangliao): generate cblas target to track all high performance
 # linear algebra libraries for cc_library(xxx SRCS xxx.c DEPS cblas)
 
-include_directories(${CBLAS_INC_DIR})
+# Use AFTER to ensure OpenBLAS system headers (e.g. /usr/local/include) are
+# appended at the end of include directories. Without this, on FreeBSD the
+# system /usr/local/include would precede third-party includes (e.g. protobuf),
+# causing the newer system protobuf headers to shadow the bundled ones.
+include_directories(AFTER SYSTEM ${CBLAS_INC_DIR})
 if(${CBLAS_PROVIDER} STREQUAL REFERENCE_CBLAS)
   target_link_libraries(cblas gfortran ${CBLAS_LIBRARIES}
                         ${REFERENCE_BLAS_LIBRARY})
