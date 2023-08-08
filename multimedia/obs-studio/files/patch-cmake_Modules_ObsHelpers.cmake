- disable Qt5 search because it fails due to missing qmake for some reason

--- cmake/Modules/ObsHelpers.cmake.orig	2023-06-18 22:05:22 UTC
+++ cmake/Modules/ObsHelpers.cmake
@@ -320,10 +320,10 @@ macro(find_qt)
   set(multiValueArgs COMPONENTS COMPONENTS_WIN COMPONENTS_MAC COMPONENTS_LINUX)
   cmake_parse_arguments(FIND_QT "" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})
   set(QT_NO_CREATE_VERSIONLESS_TARGETS ON)
-  find_package(
-    Qt5
-    COMPONENTS Core
-    QUIET)
+  #find_package(
+  #  Qt5
+  #  COMPONENTS Core
+  #  QUIET)
   find_package(
     Qt6
     COMPONENTS Core
