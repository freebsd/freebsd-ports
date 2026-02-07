--- plplotConfig.cmake.orig	2019-06-01 23:24:33 UTC
+++ plplotConfig.cmake
@@ -1,3 +1,4 @@
+# Patch borrowed from https://sourceforge.net/p/plplot/plplot/ci/52479b8830ee02900b41fe3ec947aed6b1841a48/
 if(ANY_QT_DEVICE AND PLPLOT_USE_QT5)
   # Find Qt5 components that we need to link applications against
   # the plplot library (if ENABLE_DYNDRIVERS is false) and which we
@@ -15,6 +16,15 @@ if(ANY_QT_DEVICE AND PLPLOT_USE_QT5)
     message(STATUS "WARNING: Qt5 core build-tree and install-tree inconsistency")
   endif(NOT(Qt5_FOUND AND Qt5_VERSION_MAJOR STREQUAL "${CORE_Qt5_VERSION_MAJOR}" AND Qt5_VERSION_MINOR STREQUAL "${CORE_Qt5_VERSION_MINOR}" AND Qt5_VERSION_PATCH STREQUAL "${CORE_Qt5_VERSION_PATCH}"))
 endif(ANY_QT_DEVICE AND PLPLOT_USE_QT5)
+
+if(PL_HAVE_QHULL)
+  # Maintenance(2021)
+  # Find qhull the same way as done in cmake/modules/csiro.cmake
+  find_package(Qhull CONFIG)
+  if(NOT Qhull_FOUND)
+    message(STATUS "WARNING: Qhull core build-tree and install-tree inconsistency")
+  endif(NOT Qhull_FOUND)
+endif(PL_HAVE_QHULL)
 
 # Find export files in same directory location as present file.
 include(${CMAKE_CURRENT_LIST_DIR}/plplot_exports.cmake)
