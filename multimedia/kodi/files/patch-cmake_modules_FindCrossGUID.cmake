--- cmake/modules/FindCrossGUID.cmake.orig	2022-07-08 10:04:52 UTC
+++ cmake/modules/FindCrossGUID.cmake
@@ -45,7 +45,7 @@ else()
   endif()
 
   if(CROSSGUID_FOUND)
-    find_path(CROSSGUID_INCLUDE_DIR NAMES crossguid/guid.hpp guid.h
+    find_path(CROSSGUID_INCLUDE_DIR NAMES guid.hpp guid.h
     PATHS ${PC_CROSSGUID_INCLUDEDIR})
 
     find_library(CROSSGUID_LIBRARY_RELEASE NAMES crossguid
@@ -53,7 +53,7 @@ else()
     find_library(CROSSGUID_LIBRARY_DEBUG NAMES crossguidd crossguid-dgb
           PATHS ${PC_CROSSGUID_LIBDIR})
   else()
-    find_path(CROSSGUID_INCLUDE_DIR NAMES crossguid/guid.hpp guid.h)
+    find_path(CROSSGUID_INCLUDE_DIR NAMES guid.hpp guid.h)
     find_library(CROSSGUID_LIBRARY_RELEASE NAMES crossguid)
     find_library(CROSSGUID_LIBRARY_DEBUG NAMES crossguidd)
   endif()
@@ -73,7 +73,7 @@ if(CROSSGUID_FOUND)
   set(CROSSGUID_INCLUDE_DIRS ${CROSSGUID_INCLUDE_DIR})
 
   # NEW_CROSSGUID >= 0.2.0 release
-  if(EXISTS "${CROSSGUID_INCLUDE_DIR}/crossguid/guid.hpp")
+  if(EXISTS "${CROSSGUID_INCLUDE_DIR}/guid.hpp")
     list(APPEND CROSSGUID_DEFINITIONS -DHAVE_NEW_CROSSGUID)
   endif()
 
