--- FindBento4.cmake.orig	2023-01-11 21:37:47 UTC
+++ FindBento4.cmake
@@ -49,7 +49,8 @@ if(ENABLE_INTERNAL_BENTO4)
                                  -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
                                  -DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}
                                  -DBUILD_APPS=OFF
-                      BUILD_BYPRODUCTS ${BENTO4_LIBRARY})
+                      BUILD_BYPRODUCTS ${BENTO4_LIBRARY}
+                      INSTALL_COMMAND DESTDIR= ${CMAKE_MAKE_PROGRAM} install)
 else()
   if(PKG_CONFIG_FOUND)
     pkg_check_modules(PC_BENTO4 REQUIRED)
