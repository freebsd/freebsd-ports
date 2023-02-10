--- cmake/modules/FindLibDvdNav.cmake.orig	2022-08-18 23:36:26 UTC
+++ cmake/modules/FindLibDvdNav.cmake
@@ -76,7 +76,7 @@ if(NOT TARGET LibDvdNav::LibDvdNav)
     string(APPEND LIBDVDNAV_CFLAGS " -I$<TARGET_PROPERTY:LibDvdRead::LibDvdRead,INTERFACE_INCLUDE_DIRECTORIES> $<TARGET_PROPERTY:LibDvdRead::LibDvdRead,INTERFACE_COMPILE_DEFINITIONS>")
 
     find_program(AUTORECONF autoreconf REQUIRED)
-    find_program(MAKE_EXECUTABLE make REQUIRED)
+    find_program(MAKE_EXECUTABLE gmake REQUIRED)
 
     set(CONFIGURE_COMMAND ${AUTORECONF} -vif
                   COMMAND ac_cv_path_GIT= ./configure
