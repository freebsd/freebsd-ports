--- doc/examples/cmake-multiple-shared-libraries/cmake/FindLTTngUST.cmake.orig	2022-01-27 20:18:46 UTC
+++ doc/examples/cmake-multiple-shared-libraries/cmake/FindLTTngUST.cmake
@@ -97,13 +97,13 @@ if(LTTNGUST_INCLUDE_DIRS AND LTTNGUST_INCLUDE_DIRS_GEN
     add_library(LTTng::UST UNKNOWN IMPORTED)
     set_target_properties(LTTng::UST PROPERTIES
       INTERFACE_INCLUDE_DIRECTORIES "${LTTNGUST_INCLUDE_DIRS};${LTTNGUST_INCLUDE_DIRS_GENERATED}"
-      INTERFACE_LINK_LIBRARIES ${CMAKE_DL_LIBS}
+      INTERFACE_LINK_LIBRARIES "${CMAKE_DL_LIBS}"
       IMPORTED_LINK_INTERFACE_LANGUAGES "C"
       IMPORTED_LOCATION "${LTTNGUST_LIBRARIES}")
   endif()
 
   # add libdl to required libraries
-  set(LTTNGUST_LIBRARIES ${LTTNGUST_LIBRARIES} ${CMAKE_DL_LIBS})
+  set(LTTNGUST_LIBRARIES ${LTTNGUST_LIBRARIES} "${CMAKE_DL_LIBS}")
 endif()
 
 # handle the QUIETLY and REQUIRED arguments and set LTTNGUST_FOUND to
