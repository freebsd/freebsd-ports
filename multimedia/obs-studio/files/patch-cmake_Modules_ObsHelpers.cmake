- disable Qt5 search because it fails due to missing qmake for some reason

--- cmake/Modules/ObsHelpers.cmake.orig	2022-12-29 09:06:07 UTC
+++ cmake/Modules/ObsHelpers.cmake
@@ -341,10 +341,10 @@ macro(find_qt)
   cmake_parse_arguments(FIND_QT "" "${oneValueArgs}" "${multiValueArgs}"
                         ${ARGN})
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
