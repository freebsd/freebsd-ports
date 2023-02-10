Put the internal library path first so that we can 
build with an older webkitgtk4 package installed.

Index: Source/cmake/OptionsCommon.cmake
--- Source/cmake/OptionsCommon.cmake.orig
+++ Source/cmake/OptionsCommon.cmake
@@ -180,6 +180,9 @@ if (NOT PORT STREQUAL "GTK" AND NOT PORT STREQUAL "WPE
     set(LIBEXEC_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/bin" CACHE PATH "Absolute path to install executables executed by the library")
 endif ()
 
+# make sure that the internal library dir is the first in the path
+link_directories("${CMAKE_BINARY_DIR}/lib")
+
 # Check whether features.h header exists.
 # Including glibc's one defines __GLIBC__, that is used in Platform.h
 WEBKIT_CHECK_HAVE_INCLUDE(HAVE_FEATURES_H features.h)
