--- cmake/modules/tfel.cmake.orig	2019-12-16 14:46:35 UTC
+++ cmake/modules/tfel.cmake
@@ -21,7 +21,7 @@ macro(tfel_project tfel_version_major tfel_version_min
     set(TFEL_VERSION "${VERSION}")
   endif(TFEL_VERSION_FLAVOUR)
   add_definitions("-DVERSION=\\\"\"${TFEL_VERSION}\"\\\"")
-  
+
   if(TFEL_APPEND_VERSION)
     set(TFEL_SUFFIX "${TFEL_VERSION}")
     add_definitions("-DTFEL_SUFFIX=\\\"\"${TFEL_SUFFIX}\"\\\"")
@@ -36,7 +36,7 @@ macro(tfel_project tfel_version_major tfel_version_min
     string(REPLACE "." "_" TFEL_SUFFIX_FOR_PYTHON_MODULES "${TFEL_SUFFIX}")
     string(REPLACE "-" "_" TFEL_SUFFIX_FOR_PYTHON_MODULES "${TFEL_SUFFIX_FOR_PYTHON_MODULES}")
   endif(TFEL_SUFFIX)
-  
+ 
   if(LIB_SUFFIX)
     add_definitions("-DLIB_SUFFIX=\\\"\"${LIB_SUFFIX}\"\\\"")
   endif(LIB_SUFFIX)
@@ -145,8 +145,14 @@ macro(tfel_library_internal name component)
   endif(${ARGC} LESS 2)
   add_library(${name} SHARED ${ARGN})
   if(TFEL_APPEND_SUFFIX)
+    set(export_install_path "share/tfel-${TFEL_SUFFIX}/cmake")
+  else(TFEL_APPEND_SUFFIX)
+    set(export_install_path "share/tfel/cmake")
+  endif(TFEL_APPEND_SUFFIX)
+  if(TFEL_APPEND_SUFFIX)
     set_target_properties(${name} PROPERTIES OUTPUT_NAME "${name}-${TFEL_SUFFIX}")
   endif(TFEL_APPEND_SUFFIX)
+  set_target_properties(${name} PROPERTIES VERSION ${TFEL_VERSION} SOVERSION ${TFEL_VERSION_MAJOR})
   if(WIN32)
     install(TARGETS ${name} DESTINATION bin
       COMPONENT ${component})
