Fix configure with CMake >= 3.28.0

CMake Error at /usr/local/lib/cmake/freetype/freetype-config.cmake:42 (message):
  Some (but not all) targets in this export set were already defined.

  Targets Defined: freetype

  Targets not yet defined: Freetype::Freetype

Call Stack (most recent call first):
  /usr/local/share/cmake/Modules/FindFreetype.cmake:100 (find_package)
  /usr/local/share/cmake/Modules/FindX11.cmake:351 (find_package)
  VTK/CMake/vtkModule.cmake:4573 (find_package)
  VTK/Rendering/UI/CMakeLists.txt:100 (vtk_module_find_package)

Obtained from: https://github.com/Kitware/VTK/commit/f57e941ac8017daddb216143acbcb0550ad5599c

--- VTK/CMake/FindFreetype.cmake.orig	2023-09-22 14:35:37 UTC
+++ VTK/CMake/FindFreetype.cmake
@@ -63,6 +63,64 @@ directory of a Freetype installation.
 # I'm going to attempt to cut out the middleman and hope
 # everything still works.
 
+set(_Freetype_args)
+if (Freetype_FIND_QUIETLY)
+  list(APPEND _Freetype_args
+    QUIET)
+endif ()
+if (Freetype_FIND_VERSION)
+  list(APPEND _Freetype_args
+    "${Freetype_FIND_VERSION}")
+  if (Freetype_FIND_VERSION_EXACT)
+    list(APPEND _Freetype_args
+      EXACT)
+  endif ()
+endif ()
+set(_Freetype_component_req)
+set(_Freetype_component_opt)
+foreach (_Freetype_component IN LISTS Freetype_FIND_COMPONENTS)
+  if (Freetype_FIND_REQUIRE_${_Freetype_component})
+    list(APPEND _Freetype_component_req
+      "${_Freetype_component}")
+  else ()
+    list(APPEND _Freetype_component_opt
+      "${_Freetype_component}")
+  endif ()
+endforeach ()
+unset(_Freetype_component)
+if (_Freetype_component_req)
+  list(APPEND _Freetype_args
+    COMPONENTS "${_Freetype_component_req}")
+endif ()
+unset(_Freetype_component_req)
+if (_Freetype_component_opt)
+  list(APPEND _Freetype_args
+    OPTIONAL_COMPONENTS "${_Freetype_component_opt}")
+endif ()
+unset(_Freetype_component_opt)
+find_package(freetype CONFIG ${_Freetype_args})
+unset(_Freetype_args)
+if (freetype_FOUND)
+  if (NOT TARGET Freetype::Freetype)
+    add_library(Freetype::Freetype IMPORTED INTERFACE)
+    set_target_properties(Freetype::Freetype PROPERTIES
+      INTERFACE_LINK_LIBRARIES freetype)
+  endif ()
+  get_property(FREETYPE_INCLUDE_DIRS TARGET freetype PROPERTY INTERFACE_INCLUDE_DIRECTORIES)
+  get_property(FREETYPE_LIBRARIES TARGET freetype PROPERTY INTERFACE_LINK_LIBRARIES)
+  get_property(_Freetype_location TARGET freetype PROPERTY LOCATION)
+  list(APPEND FREETYPE_LIBRARIES
+    "${_Freetype_location}")
+  unset(_Freetype_location)
+  set(Freetype_FOUND 1)
+  set(FREETYPE_VERSION_STRING "${freetype_VERSION}")
+  foreach (_Freetype_component IN LISTS Freetype_FIND_COMPONENTS)
+    set(Freetype_${_Freetype_component}_FOUND "${freetype_${_Freetype_component}_FOUND}")
+  endforeach ()
+  unset(_Freetype_component)
+  return ()
+endif ()
+
 set(FREETYPE_FIND_ARGS
   HINTS
     ENV FREETYPE_DIR
