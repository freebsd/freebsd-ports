--- cmake/modules/FindCrossGUID.cmake.orig	2024-03-04 21:39:38 UTC
+++ cmake/modules/FindCrossGUID.cmake
@@ -45,7 +45,7 @@ if(NOT TARGET CrossGUID::CrossGUID)
       set(CROSSGUID_VERSION ${PC_CROSSGUID_VERSION})
     endif()
 
-    find_path(CROSSGUID_INCLUDE_DIR NAMES crossguid/guid.hpp guid.h
+    find_path(CROSSGUID_INCLUDE_DIR NAMES guid.hpp guid.h
                                     HINTS ${DEPENDS_PATH}/include ${PC_CROSSGUID_INCLUDEDIR}
                                     ${${CORE_PLATFORM_LC}_SEARCH_CONFIG}
                                     NO_CACHE)
@@ -59,7 +59,7 @@ if(NOT TARGET CrossGUID::CrossGUID)
                                          NO_CACHE)
 
     # NEW_CROSSGUID >= 0.2.0 release
-    if(EXISTS "${CROSSGUID_INCLUDE_DIR}/crossguid/guid.hpp")
+    if(EXISTS "${CROSSGUID_INCLUDE_DIR}/guid.hpp")
       list(APPEND _crossguid_definitions HAVE_NEW_CROSSGUID)
     endif()
   endif()
