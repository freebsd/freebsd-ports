--- cmake/Install.cmake.orig	2026-03-28 04:56:37 UTC
+++ cmake/Install.cmake
@@ -126,7 +126,7 @@ fish_create_dirs(
     ${rel_datadir}/fish/vendor_conf.d
 )
 
-fish_try_create_dirs(${rel_datadir}/pkgconfig)
+fish_try_create_dirs(${rel_datadir}/../libdata/pkgconfig)
 configure_file(fish.pc.in fish.pc.noversion @ONLY)
 
 add_custom_command(
@@ -142,7 +142,7 @@ install(
 
 install(
     FILES ${CMAKE_CURRENT_BINARY_DIR}/fish.pc
-    DESTINATION ${rel_datadir}/pkgconfig
+    DESTINATION ${rel_datadir}/../libdata/pkgconfig
 )
 
 install(
