--- cmake/modules/FindLibDvdCSS.cmake.orig	2022-08-18 23:36:30 UTC
+++ cmake/modules/FindLibDvdCSS.cmake
@@ -63,7 +63,7 @@ if(ENABLE_DVDCSS)
                    ${LIBDVD_ADDITIONAL_ARGS})
   else()
     find_program(AUTORECONF autoreconf REQUIRED)
-    find_program(MAKE_EXECUTABLE make REQUIRED)
+    find_program(MAKE_EXECUTABLE gmake REQUIRED)
 
     set(CONFIGURE_COMMAND ${AUTORECONF} -vif
                   COMMAND ac_cv_path_GIT= ./configure
