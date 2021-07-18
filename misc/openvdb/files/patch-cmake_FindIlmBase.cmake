--- cmake/FindIlmBase.cmake.orig	2021-06-11 21:38:41 UTC
+++ cmake/FindIlmBase.cmake
@@ -10,7 +10,7 @@ Find IlmBase include dirs and libraries
 
 Use this module by invoking find_package with the form::
 
-  find_package(IlmBase
+  find_package(Imath
     [version] [EXACT]      # Minimum or EXACT version
     [REQUIRED]             # Fail with error if IlmBase is not found
     [COMPONENTS <libs>...] # IlmBase libraries by their canonical name
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
 ``IlmBase_RELEASE_LIBRARIES``
   Libraries needed to link to the release version of IlmBase.
@@ -65,7 +65,7 @@ Cache Variables
 
 The following cache variables may also be set:
 
-``IlmBase_INCLUDE_DIR``
+````
   The directory containing ``IlmBase/config-auto.h``.
 ``IlmBase_{COMPONENT}_LIBRARY``
   Individual component libraries for IlmBase. may include target_link_libraries() debug/optimized keywords.
@@ -102,7 +102,7 @@ include(GNUInstallDirs)
 
 
 mark_as_advanced(
-  IlmBase_INCLUDE_DIR
+  
   IlmBase_LIBRARY
 )
 
@@ -112,10 +112,6 @@ if(DISABLE_CMAKE_SEARCH_PATHS)
 endif()
 
 set(_ILMBASE_COMPONENT_LIST
-  Half
-  Iex
-  IexMath
-  IlmThread
   Imath
 )
 
@@ -177,15 +173,15 @@ list(APPEND _ILMBASE_INCLUDE_SEARCH_DIRS
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
@@ -193,7 +189,7 @@ if(EXISTS "${IlmBase_INCLUDE_DIR}/IlmBaseConfig.h")
   )
   string(STRIP "${_ilmbase_version_major_string}" IlmBase_VERSION_MAJOR)
 
-  file(STRINGS "${IlmBase_INCLUDE_DIR}/IlmBaseConfig.h"
+  file(STRINGS "${}/IlmBaseConfig.h"
      _ilmbase_version_minor_string REGEX "#define ILMBASE_VERSION_MINOR "
   )
   string(REGEX REPLACE "#define ILMBASE_VERSION_MINOR" ""
@@ -324,16 +320,16 @@ endforeach()
 # ------------------------------------------------------------------------
 
 include(FindPackageHandleStandardArgs)
-find_package_handle_standard_args(IlmBase
-  FOUND_VAR IlmBase_FOUND
+find_package_handle_standard_args(Imath
+  FOUND_VAR Imath_FOUND
   REQUIRED_VARS
-    IlmBase_INCLUDE_DIR
-    IlmBase_LIB_COMPONENTS
-  VERSION_VAR IlmBase_VERSION
+#    IlmBase_INCLUDE_DIR
+    Imath_LIB_COMPONENTS
+  VERSION_VAR Imath_VERSION
   HANDLE_COMPONENTS
 )
 
-if(NOT IlmBase_FOUND)
+if(NOT Imath_FOUND)
   if(IlmBase_FIND_REQUIRED)
     message(FATAL_ERROR "Unable to find IlmBase")
   endif()
@@ -348,8 +344,8 @@ set(IlmBase_DEBUG_LIBRARIES "")
 set(IlmBase_DEBUG_LIBRARY_DIRS "")
 foreach(LIB ${IlmBase_LIB_COMPONENTS_RELEASE})
   get_filename_component(_ILM_LIBDIR ${LIB} DIRECTORY)
-  list(APPEND IlmBase_RELEASE_LIBRARIES ${LIB})
-  list(APPEND IlmBase_RELEASE_LIBRARY_DIRS ${_ILM_LIBDIR})
+  list(APPEND Imath_RELEASE_LIBRARIES ${LIB})
+  list(APPEND Imath_RELEASE_LIBRARY_DIRS ${_ILM_LIBDIR})
 endforeach()
 
 foreach(LIB ${IlmBase_LIB_COMPONENTS_DEBUG})
@@ -377,12 +373,12 @@ set(IlmBase_LIBRARY_DIRS ${IlmBase_RELEASE_LIBRARY_DIR
 
 set(_IlmBase_Parent_Dir "")
 get_filename_component(_IlmBase_Parent_Dir
-  ${IlmBase_INCLUDE_DIR}/../ ABSOLUTE)
+  ${}/../ ABSOLUTE)
 
-set(IlmBase_INCLUDE_DIRS)
-list(APPEND IlmBase_INCLUDE_DIRS
+set(S)
+list(APPEND S
   ${_IlmBase_Parent_Dir}
-  ${IlmBase_INCLUDE_DIR}
+  ${}
 )
 unset(_IlmBase_Parent_Dir)
 
@@ -419,7 +415,7 @@ foreach(COMPONENT ${IlmBase_FIND_COMPONENTS})
     set_target_properties(IlmBase::${COMPONENT} PROPERTIES
       INTERFACE_COMPILE_OPTIONS "${PC_IlmBase_CFLAGS_OTHER}"
       INTERFACE_COMPILE_DEFINITIONS "${IlmBase_${COMPONENT}_DEFINITIONS}"
-      INTERFACE_INCLUDE_DIRECTORIES "${IlmBase_INCLUDE_DIRS}")
+      INTERFACE_INCLUDE_DIRECTORIES "${S}")
 
     # Standard location
     set_target_properties(IlmBase::${COMPONENT} PROPERTIES
