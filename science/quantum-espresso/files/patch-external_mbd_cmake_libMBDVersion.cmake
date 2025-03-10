--- external/mbd/cmake/libMBDVersion.cmake.orig	2025-01-27 00:55:20 UTC
+++ external/mbd/cmake/libMBDVersion.cmake
@@ -22,13 +22,15 @@ elseif(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/cmake/libMB
     message(STATUS "Setting version tag to ${VERSION_TAG} from Git")
 elseif(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/cmake/libMBDVersionTag.cmake")
     include(libMBDVersionTag)
-else()
+elseif(FALSE)
     message(FATAL_ERROR
         "Not in a Git repository and version tag is missing, you most likely "
         "attempt to install from a copy of the source tree. Obtain the source "
         "distribution (libmbd-<version>.tar.gz) from a Github release page "
         "instead.")
 endif()
+
+set(VERSION_TAG "1.0.0")
 
 set(PROJECT_VERSION ${VERSION_TAG})
 
