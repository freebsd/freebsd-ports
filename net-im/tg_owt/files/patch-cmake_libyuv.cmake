--- cmake/libyuv.cmake.orig	2021-02-03 11:42:41 UTC
+++ cmake/libyuv.cmake
@@ -126,7 +126,7 @@ else()
 endif()
 
 target_include_directories(libyuv
-PUBLIC
+BEFORE PUBLIC
     $<BUILD_INTERFACE:${libyuv_loc}/include>
     $<INSTALL_INTERFACE:${webrtc_includedir}/third_party/libyuv/include>
 )
