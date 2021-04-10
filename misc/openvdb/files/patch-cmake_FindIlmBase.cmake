--- cmake/FindIlmBase.cmake.orig	2021-02-05 19:21:38 UTC
+++ cmake/FindIlmBase.cmake
@@ -36,11 +36,11 @@ Result Variables
 
 This will define the following variables:
 
-``IlmBase_FOUND``
-  True if the system has the IlmBase library.
+``Imath_FOUND``
+  True if the system has the Imath library.
 ``IlmBase_VERSION``
   The version of the IlmBase library which was found.
-``IlmBase_INCLUDE_DIRS``
+``S``
   Include directories needed to use IlmBase.
 ``IlmBase_LIBRARIES``
   Libraries needed to link to IlmBase.
@@ -54,7 +54,7 @@ Cache Variables
 
 The following cache variables may also be set:
 
-``IlmBase_INCLUDE_DIR``
+````
   The directory containing ``IlmBase/config-auto.h``.
 ``IlmBase_{COMPONENT}_LIBRARY``
   Individual component libraries for IlmBase
@@ -85,7 +85,7 @@ include(GNUInstallDirs)
 
 
 mark_as_advanced(
-  IlmBase_INCLUDE_DIR
+  
   IlmBase_LIBRARY
 )
 
@@ -95,10 +95,6 @@ if(DISABLE_CMAKE_SEARCH_PATHS)
 endif()
 
 set(_ILMBASE_COMPONENT_LIST
-  Half
-  Iex
-  IexMath
-  IlmThread
   Imath
 )
 
@@ -142,7 +138,7 @@ if(USE_PKGCONFIG)
   if(NOT DEFINED PKG_CONFIG_FOUND)
     find_package(PkgConfig)
   endif()
-  pkg_check_modules(PC_IlmBase QUIET IlmBase)
+  pkg_check_modules(PC_IlmBase QUIET Imath)
 endif()
 
 # ------------------------------------------------------------------------
@@ -158,15 +154,15 @@ list(APPEND _ILMBASE_INCLUDE_SEARCH_DIRS
 )
 
 # Look for a standard IlmBase header file.
-find_path(IlmBase_INCLUDE_DIR IlmBaseConfig.h
+find_path( IlmBaseConfig.h
   ${_FIND_ILMBASE_ADDITIONAL_OPTIONS}
   PATHS ${_ILMBASE_INCLUDE_SEARCH_DIRS}
   PATH_SUFFIXES ${CMAKE_INSTALL_INCLUDEDIR}/OpenEXR include/OpenEXR OpenEXR
 )
 
-if(EXISTS "${IlmBase_INCLUDE_DIR}/IlmBaseConfig.h")
+if(EXISTS "${}/IlmBaseConfig.h")
   # Get the ILMBASE version information from the config header
-  file(STRINGS "${IlmBase_INCLUDE_DIR}/IlmBaseConfig.h"
+  file(STRINGS "${}/IlmBaseConfig.h"
     _ilmbase_version_major_string REGEX "#define ILMBASE_VERSION_MAJOR "
   )
   string(REGEX REPLACE "#define ILMBASE_VERSION_MAJOR" ""
@@ -174,7 +170,7 @@ if(EXISTS "${IlmBase_INCLUDE_DIR}/IlmBaseConfig.h")
   )
   string(STRIP "${_ilmbase_version_major_string}" IlmBase_VERSION_MAJOR)
 
-  file(STRINGS "${IlmBase_INCLUDE_DIR}/IlmBaseConfig.h"
+  file(STRINGS "${}/IlmBaseConfig.h"
      _ilmbase_version_minor_string REGEX "#define ILMBASE_VERSION_MINOR "
   )
   string(REGEX REPLACE "#define ILMBASE_VERSION_MINOR" ""
@@ -255,16 +251,16 @@ unset(_ILMBASE_ORIG_CMAKE_FIND_LIBRARY_SUFFIXES)
 # ------------------------------------------------------------------------
 
 include(FindPackageHandleStandardArgs)
-find_package_handle_standard_args(IlmBase
-  FOUND_VAR IlmBase_FOUND
+find_package_handle_standard_args(Imath
+  FOUND_VAR Imath_FOUND
   REQUIRED_VARS
-    IlmBase_INCLUDE_DIR
+    
     IlmBase_LIB_COMPONENTS
   VERSION_VAR IlmBase_VERSION
   HANDLE_COMPONENTS
 )
 
-if(IlmBase_FOUND)
+if(Imath_FOUND)
   set(IlmBase_LIBRARIES ${IlmBase_LIB_COMPONENTS})
 
   # We have to add both include and include/OpenEXR to the include
@@ -280,12 +276,12 @@ if(IlmBase_FOUND)
 
   set(_IlmBase_Parent_Dir "")
   get_filename_component(_IlmBase_Parent_Dir
-    ${IlmBase_INCLUDE_DIR}/../ ABSOLUTE)
+    ${}/../ ABSOLUTE)
 
-  set(IlmBase_INCLUDE_DIRS)
-  list(APPEND IlmBase_INCLUDE_DIRS
+  set(S)
+  list(APPEND S
     ${_IlmBase_Parent_Dir}
-    ${IlmBase_INCLUDE_DIR}
+    ${}
   )
   unset(_IlmBase_Parent_Dir)
 
@@ -330,7 +326,7 @@ if(IlmBase_FOUND)
         IMPORTED_LOCATION "${IlmBase_${COMPONENT}_LIBRARY}"
         INTERFACE_COMPILE_OPTIONS "${PC_IlmBase_CFLAGS_OTHER}"
         INTERFACE_COMPILE_DEFINITIONS "${IlmBase_${COMPONENT}_DEFINITIONS}"
-        INTERFACE_INCLUDE_DIRECTORIES "${IlmBase_INCLUDE_DIRS}"
+        INTERFACE_INCLUDE_DIRECTORIES "${S}"
       )
     endif()
   endforeach()
