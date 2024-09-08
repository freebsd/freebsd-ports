--- cmake/FindGuile.cmake.orig	2024-08-09 20:31:24 UTC
+++ cmake/FindGuile.cmake
@@ -12,87 +12,42 @@
 # GUILE_SITE_DIR         - site dir
 # GUILE_EXTENSION_DIR    - extension dir
 # GUILE_ROOT_DIR         - prefix dir
+find_package(PkgConfig REQUIRED)
 
-# Look for the header file
-# Look for guile-2.2 first, then 2.0, then 1.8
-# Macports for OSX puts things in /opt/local
-find_path (GUILE_INCLUDE_DIR libguile.h
-  PATH_SUFFIXES
-    guile/3.0
-    guile/2.2
-    guile/2.0
-    guile/1.8
-    libguile
-    guile
-  HINTS /opt/local/include
-)
-
-# Look for the library
-find_library (GUILE_LIBRARY NAMES guile-3.0 guile-2.2 guile-2.0 guile
-  HINTS
-    /opt/local/lib
-)
-
-
-set (GUILE_LIBRARIES ${GUILE_LIBRARY})
-set (GUILE_INCLUDE_DIRS ${GUILE_INCLUDE_DIR})
-
-
-# check guile's version if we're using cmake >= 2.6
-if (GUILE_INCLUDE_DIR)
-  SET(GUILE_VERSION_MAJOR 0)
-  SET(GUILE_VERSION_MINOR 0)
-  SET(GUILE_VERSION_PATCH 0)
-
-  IF(NOT EXISTS "${GUILE_INCLUDE_DIR}/libguile/version.h")
-          MESSAGE(FATAL_ERROR "Found ${GUILE_INCLUDE_DIR}/libguile.h but not version.h; check your guile installation!")
-  ENDIF(NOT EXISTS "${GUILE_INCLUDE_DIR}/libguile/version.h")
-
-  # Extract the libguile version from the 'version.h' file
-  SET(GUILE_MAJOR_VERSION 0)
-  FILE(READ "${GUILE_INCLUDE_DIR}/libguile/version.h" _GUILE_VERSION_H_CONTENTS)
-
-  STRING(REGEX MATCH "#define SCM_MAJOR_VERSION[	 ]+([0-9])" _MATCH "${_GUILE_VERSION_H_CONTENTS}")
-  SET(GUILE_VERSION_MAJOR ${CMAKE_MATCH_1})
-  STRING(REGEX MATCH "#define SCM_MINOR_VERSION[	 ]+([0-9]+)" _MATCH "${_GUILE_VERSION_H_CONTENTS}")
-  SET(GUILE_VERSION_MINOR ${CMAKE_MATCH_1})
-  STRING(REGEX MATCH "#define SCM_MICRO_VERSION[	 ]+([0-9]+)" _MATCH "${_GUILE_VERSION_H_CONTENTS}")
-  SET(GUILE_VERSION_PATCH ${CMAKE_MATCH_1})
-
-  SET(GUILE_VERSION_STRING "${GUILE_VERSION_MAJOR}.${GUILE_VERSION_MINOR}.${GUILE_VERSION_PATCH}")
-
-endif ()
-
 find_program(GUILE_EXECUTABLE
               NAMES guile3.0 guile2.2 guile2.0 guile
            )
-
 find_program(GUILE_CONFIG_EXECUTABLE
               NAMES guile-config3.0 guile-config2.2 guile-config2.0 guile-config
            )
 
+pkg_check_modules(GUILE IMPORTED_TARGET guile)
+if (GUILE_FOUND)
+  pkg_get_variable(GUILE_ROOT_DIR guile prefix)
+  pkg_get_variable(GUILE_SITE_DIR guile sitedir)
+  pkg_get_variable(GUILE_EXTENSION_DIR guile extensiondir)
+else()
+  pkg_check_modules(GUILE IMPORTED_TARGET guile-2.0>=2.0)
+endif()
+if (GUILE_FOUND)
+  pkg_get_variable(GUILE_ROOT_DIR guile-2.0 prefix)
+  pkg_get_variable(GUILE_SITE_DIR guile-2.0 sitedir)
+  pkg_get_variable(GUILE_EXTENSION_DIR guile-2.0 extensiondir)
+else()
+  pkg_check_modules(GUILE REQUIRED IMPORTED_TARGET guile-3.0>=3.0)
+  pkg_get_variable(GUILE_ROOT_DIR guile-3.0 prefix)
+  pkg_get_variable(GUILE_SITE_DIR guile-3.0 sitedir)
+  pkg_get_variable(GUILE_EXTENSION_DIR guile-3.0 extensiondir)
+endif()
+message(STATUS "GUILE_VERSION is set to ${GUILE_VERSION}")
+message(STATUS "GUILE_ROOT_DIR is set to ${GUILE_ROOT_DIR}")
+message(STATUS "GUILE_SITE_DIR is set to ${GUILE_SITE_DIR}")
+message(STATUS "GUILE_EXTENSION_DIR is set to ${GUILE_EXTENSION_DIR}")
+message(STATUS "GUILE_EXECUTABLE is set to ${GUILE_EXECUTABLE}")
+message(STATUS "GUILE_CONFIG_EXECUTABLE is set to ${GUILE_CONFIG_EXECUTABLE}")
 
-if (GUILE_CONFIG_EXECUTABLE)
-  execute_process (COMMAND ${GUILE_CONFIG_EXECUTABLE} info prefix
-                    OUTPUT_VARIABLE GUILE_ROOT_DIR
-                    OUTPUT_STRIP_TRAILING_WHITESPACE)
-
-  execute_process (COMMAND ${GUILE_CONFIG_EXECUTABLE} info sitedir
-                    OUTPUT_VARIABLE GUILE_SITE_DIR
-                    OUTPUT_STRIP_TRAILING_WHITESPACE)
-
-  execute_process (COMMAND ${GUILE_CONFIG_EXECUTABLE} info extensiondir
-                    OUTPUT_VARIABLE GUILE_EXTENSION_DIR
-                    OUTPUT_STRIP_TRAILING_WHITESPACE)
-endif ()
-
-# IF(GUILE_FOUND AND GUILE_VERSION_MAJOR EQUAL 2)
-# 	ADD_DEFINITIONS(-DHAVE_GUILE2)
-# ENDIF(GUILE_FOUND AND GUILE_VERSION_MAJOR EQUAL 2)
-
 # handle REQUIRED and QUIET options
 include (FindPackageHandleStandardArgs)
-find_package_handle_standard_args (Guile REQUIRED_VARS GUILE_EXECUTABLE GUILE_ROOT_DIR GUILE_INCLUDE_DIRS GUILE_LIBRARIES VERSION_VAR GUILE_VERSION_STRING)
-
+find_package_handle_standard_args (Guile REQUIRED_VARS GUILE_SITE_DIR GUILE_EXTENSION_DIR GUILE_ROOT_DIR GUILE_INCLUDE_DIRS GUILE_LIBRARIES GUILE_CFLAGS GUILE_LDFLAGS GUILE_VERSION)
 
 mark_as_advanced (GUILE_INCLUDE_DIR GUILE_LIBRARY)
