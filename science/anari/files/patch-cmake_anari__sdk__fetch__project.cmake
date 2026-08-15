--- cmake/anari_sdk_fetch_project.cmake.orig	2026-07-19 23:31:40 UTC
+++ cmake/anari_sdk_fetch_project.cmake
@@ -11,18 +11,7 @@ function(anari_sdk_fetch_project)
     ${ARGN}
   )
 
-  if (FETCH_SOURCE_MD5)
-    set(FETCH_SOURCE_MD5_COMMAND URL_MD5 ${FETCH_SOURCE_MD5})
-  endif()
-
   set(SOURCE ${CMAKE_BINARY_DIR}/deps/source/${FETCH_SOURCE_NAME})
-
-  FetchContent_Populate(${FETCH_SOURCE_NAME}
-    URL ${FETCH_SOURCE_URL}
-    DOWNLOAD_DIR ${CMAKE_SOURCE_DIR}/.anari_deps/${FETCH_SOURCE_NAME}
-    ${FETCH_SOURCE_MD5_COMMAND}
-    SOURCE_DIR ${SOURCE}
-  )
 
   set("${FETCH_SOURCE_NAME}_LOCATION" ${SOURCE} PARENT_SCOPE)
 
