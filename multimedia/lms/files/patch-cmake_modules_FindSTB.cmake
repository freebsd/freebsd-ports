- workaround for https://github.com/epoupon/lms/issues/207

--- cmake/modules/FindSTB.cmake.orig	2022-03-10 16:21:18 UTC
+++ cmake/modules/FindSTB.cmake
@@ -1,4 +1,4 @@
-find_path(STB_INCLUDE_DIR stb/stb.h)
+find_path(STB_INCLUDE_DIR stb/stb_image.h)
 
 include(FindPackageHandleStandardArgs)
 
