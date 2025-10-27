--- MySQL/ThirdPartyDownloads/Orthanc-1.12.9/OrthancFramework/Resources/CMake/ProtobufConfiguration.cmake.orig	2025-08-11 16:02:50 UTC
+++ MySQL/ThirdPartyDownloads/Orthanc-1.12.9/OrthancFramework/Resources/CMake/ProtobufConfiguration.cmake
@@ -60,27 +60,31 @@ else()
     add_custom_target(ProtobufCompiler)
   endif()
   
-  check_include_file_cxx(google/protobuf/any.h HAVE_PROTOBUF_H)
-  if (NOT HAVE_PROTOBUF_H)
-    message(FATAL_ERROR "Please install the libprotobuf-dev package")
-  endif()
+  if (${CMAKE_SYSTEM_NAME} STREQUAL "FreeBSD")
+    find_package(Protobuf REQUIRED)
+  else()
+    check_include_file_cxx(google/protobuf/any.h HAVE_PROTOBUF_H)
+    if (NOT HAVE_PROTOBUF_H)
+      message(FATAL_ERROR "Please install the libprotobuf-dev package")
+    endif()
 
-  set(CMAKE_REQUIRED_LIBRARIES "protobuf")
+    set(CMAKE_REQUIRED_LIBRARIES "protobuf")
 
-  include(CheckCXXSourceCompiles) 
-  check_cxx_source_compiles(
-    "
+    include(CheckCXXSourceCompiles) 
+    check_cxx_source_compiles(
+      "
 #include <google/protobuf/descriptor.h>
 int main()
 {
   google::protobuf::FieldDescriptor::TypeName(google::protobuf::FieldDescriptor::TYPE_FLOAT);
 }
-"  HAVE_PROTOBUF_LIB)
-  if (NOT HAVE_PROTOBUF_LIB)
-    message(FATAL_ERROR "Cannot find the protobuf library")
-  endif()
+  "  HAVE_PROTOBUF_LIB)
+    if (NOT HAVE_PROTOBUF_LIB)
+      message(FATAL_ERROR "Cannot find the protobuf library")
+    endif()
   
-  unset(CMAKE_REQUIRED_LIBRARIES)
+    unset(CMAKE_REQUIRED_LIBRARIES)
+  endif()
 
   link_libraries(protobuf)
 endif()
