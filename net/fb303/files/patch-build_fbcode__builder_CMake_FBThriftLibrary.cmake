--- build/fbcode_builder/CMake/FBThriftLibrary.cmake.orig	2020-09-15 21:55:13 UTC
+++ build/fbcode_builder/CMake/FBThriftLibrary.cmake
@@ -43,7 +43,7 @@ function(add_fbthrift_library LIB_NAME THRIFT_FILE)
   set(PY_DEPENDS)
   foreach(dep IN LISTS ARG_DEPENDS)
     list(APPEND CPP_DEPENDS "${dep}_cpp")
-    list(APPEND PY_DEPENDS "${dep}_py")
+    #list(APPEND PY_DEPENDS "${dep}_py")
   endforeach()
 
   foreach(lang IN LISTS ARG_LANGUAGES)
@@ -56,7 +56,7 @@ function(add_fbthrift_library LIB_NAME THRIFT_FILE)
         INCLUDE_DIR "${ARG_INCLUDE_DIR}"
         THRIFT_INCLUDE_DIR "${ARG_THRIFT_INCLUDE_DIR}"
       )
-    elseif ("${lang}" STREQUAL "py" OR "${lang}" STREQUAL "python")
+    elseif (FALSE AND "${lang}" STREQUAL "py" OR "${lang}" STREQUAL "python")
       if (DEFINED ARG_PY_NAMESPACE)
         set(namespace_args NAMESPACE "${ARG_PY_NAMESPACE}")
       endif()
