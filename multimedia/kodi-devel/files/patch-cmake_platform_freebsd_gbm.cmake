--- cmake/platform/freebsd/gbm.cmake.orig	2019-05-08 08:47:45 UTC
+++ cmake/platform/freebsd/gbm.cmake
@@ -1 +1,2 @@
 include(cmake/platform/linux/gbm.cmake)
+list(APPEND PLATFORM_REQUIRED_DEPS EpollShim)
