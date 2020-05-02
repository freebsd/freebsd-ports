--- Telegram/cmake/lib_tgvoip.cmake.orig	2020-04-30 01:34:51 UTC
+++ Telegram/cmake/lib_tgvoip.cmake
@@ -778,11 +778,17 @@ else()
         )
     endif()
 
+    find_package(PkgConfig REQUIRED)
+    pkg_check_modules(PULSE REQUIRED IMPORTED_TARGET libpulse)
+    pkg_check_modules(ALSA REQUIRED IMPORTED_TARGET alsa)
+
     target_include_directories(lib_tgvoip
     PUBLIC
         ${tgvoip_loc}
     PRIVATE
         ${tgvoip_loc}/webrtc_dsp
+        ${PULSE_INCLUDE_DIRS}
+        ${ALSA_INCLUDE_DIRS}
     )
 
     target_link_libraries(lib_tgvoip
