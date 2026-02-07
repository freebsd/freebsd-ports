--- cmake/libgav1_install.cmake.orig	2024-11-23 08:48:59 UTC
+++ cmake/libgav1_install.cmake
@@ -33,7 +33,7 @@ macro(libgav1_setup_install_target)
     configure_file("${libgav1_root}/cmake/libgav1.pc.template"
                    "${libgav1_build}/libgav1.pc" @ONLY NEWLINE_STYLE UNIX)
     install(FILES "${libgav1_build}/libgav1.pc"
-            DESTINATION "${prefix}/${CMAKE_INSTALL_LIBDIR}/pkgconfig")
+            DESTINATION "${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig")
 
     # CMake config: libgav1-config.cmake
     set(LIBGAV1_INCLUDE_DIRS "${prefix}/${CMAKE_INSTALL_INCLUDEDIR}")
