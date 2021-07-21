--- cmake/options_linux.cmake.orig	2021-07-13 19:08:45 UTC
+++ cmake/options_linux.cmake
@@ -58,11 +58,6 @@ if (DESKTOP_APP_SPECIAL_TARGET)
     endif()
 endif()
 
-target_link_libraries(common_options
-INTERFACE
-    desktop-app::external_jemalloc
-)
-
 if (DESKTOP_APP_USE_PACKAGED)
     find_library(ATOMIC_LIBRARY atomic)
 else()
