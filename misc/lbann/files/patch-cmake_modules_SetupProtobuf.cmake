- https://gitlab.kitware.com/cmake/cmake/-/issues/24218

--- cmake/modules/SetupProtobuf.cmake.orig	2022-12-02 19:45:09 UTC
+++ cmake/modules/SetupProtobuf.cmake
@@ -65,7 +65,7 @@ else ()
     PATH_SUFFIXES lib64/cmake/protobuf lib/cmake/protobuf
     NO_DEFAULT_PATH)
   if(NOT Protobuf_FOUND)
-    find_package(Protobuf "${PROTOBUF_MIN_VERSION}" CONFIG QUIET REQUIRED)
+    find_package(Protobuf "${PROTOBUF_MIN_VERSION}" QUIET REQUIRED)
   endif ()
   message(STATUS "Found Protobuf: ${Protobuf_DIR}")
 endif ()
