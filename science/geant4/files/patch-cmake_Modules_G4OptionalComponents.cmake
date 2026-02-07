--- cmake/Modules/G4OptionalComponents.cmake.orig	2023-12-10 17:01:37 UTC
+++ cmake/Modules/G4OptionalComponents.cmake
@@ -38,8 +38,31 @@ endif()
 
 option(GEANT4_USE_SYSTEM_CLHEP "Use system CLHEP library" ${_default_use_system_clhep})
 
+#[[CLHEP installs CMake Config files not, e.g., to '<prefix>/libdata/CLHEP/' (where CMake
+   would have no trouble finding the files), but to '<prefix>/libdata/CLHEP-<VERSION>/'.
+   There is no straight-forward way to communicate this to CMake's `find_package`, but
+   we can provide a list of additional PATHS for CMake to try as *prefixes*.
+   We find all absolute paths from the system's pre-defined prefixes to directories
+   containing a file "CLHEPConfig.cmake" and provide these paths as prefixes, slightly
+   abusing the fact that one of CMake's search paths is just '<prefix>/'.
+   See https://cmake.org/cmake/help/latest/command/find_package.html#config-mode-search-procedure.]]
+unset(_paths)
+foreach(_prefix ${CMAKE_SYSTEM_PREFIX_PATH})
+  file(GLOB _find_results ${_prefix}/*/CLHEP*)
+  list(APPEND _paths ${_find_results})
+endforeach()
+list(REMOVE_DUPLICATES _paths)
+foreach(_path ${_paths})
+  file(GLOB _find_results ${_path}/CLHEPConfig.cmake)
+  if("${_find_results}" STREQUAL "")
+    list(REMOVE_ITEM _paths ${_path})
+  endif()
+endforeach()
+unset(_find_results)
 if(GEANT4_USE_SYSTEM_CLHEP)
-  find_package(CLHEP 2.4.6.0 REQUIRED CONFIG)
+  find_package(CLHEP 2.4.6.0 REQUIRED CONFIG
+      PATHS ${_paths}) # PATHS added by port maintainer
+  unset(_paths)
   geant4_save_package_variables(CLHEP CLHEP_DIR)
 else()
   set(CLHEP_FOUND TRUE)
