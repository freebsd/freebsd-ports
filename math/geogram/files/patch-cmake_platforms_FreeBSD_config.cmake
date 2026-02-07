--- cmake/platforms/FreeBSD/config.cmake.orig	2018-12-09 17:34:34 UTC
+++ cmake/platforms/FreeBSD/config.cmake
@@ -0,0 +1,5 @@
+set(VORPALINE_ARCH_64 true)
+include(${GEOGRAM_SOURCE_DIR}/cmake/platforms/FreeBSD-clang.cmake)
+#add_flags(CMAKE_CXX_FLAGS -m64)
+#add_flags(CMAKE_C_FLAGS -m64)
+
