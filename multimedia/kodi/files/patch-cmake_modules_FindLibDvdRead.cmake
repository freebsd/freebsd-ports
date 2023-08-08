--- cmake/modules/FindLibDvdRead.cmake.orig	2022-08-18 23:36:34 UTC
+++ cmake/modules/FindLibDvdRead.cmake
@@ -81,7 +81,7 @@ if(NOT TARGET LibDvdRead::LibDvdRead)
     endif()
 
     find_program(AUTORECONF autoreconf REQUIRED)
-    find_program(MAKE_EXECUTABLE make REQUIRED)
+    find_program(MAKE_EXECUTABLE gmake REQUIRED)
 
     set(CONFIGURE_COMMAND ${AUTORECONF} -vif
                   COMMAND ac_cv_path_GIT= ./configure
