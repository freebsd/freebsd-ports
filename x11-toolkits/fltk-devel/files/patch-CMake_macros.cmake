--- CMake/macros.cmake.orig	2014-10-08 14:15:49.000000000 +0200
+++ CMake/macros.cmake	2014-10-08 14:17:23.000000000 +0200
@@ -65,9 +65,9 @@
 
     install(TARGETS ${LIBRARY_NAME}
         EXPORT FLTK-Targets
-        RUNTIME DESTINATION bin
-        LIBRARY DESTINATION lib
-        ARCHIVE DESTINATION lib
+        RUNTIME DESTINATION bin/fltk-devel
+        LIBRARY DESTINATION lib/fltk-devel
+        ARCHIVE DESTINATION lib/fltk-devel
         )
 
     list(APPEND FLTK_LIBRARIES "${LIBRARY_NAME}")
