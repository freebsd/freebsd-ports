--- cmake/Install.cmake.orig	2026-09-04 11:36:56 UTC
+++ cmake/Install.cmake
@@ -71,7 +71,7 @@ function(FISH_TRY_CREATE_DIRS)
         else()
             set(abs_dir "\$ENV{DESTDIR}${dir}")
         endif()
-        install(SCRIPT CODE "
+        install(CODE "
             EXECUTE_PROCESS(COMMAND mkdir -p ${abs_dir} OUTPUT_QUIET ERROR_QUIET)
             execute_process(COMMAND chmod 755 ${abs_dir} OUTPUT_QUIET ERROR_QUIET)
         ")
@@ -118,7 +118,7 @@ fish_create_dirs(
     ${rel_datadir}/fish/vendor_conf.d
 )
 
-fish_try_create_dirs(${rel_datadir}/pkgconfig)
+fish_try_create_dirs(${rel_datadir}/../libdata/pkgconfig)
 configure_file(fish.pc.in fish.pc.noversion @ONLY)
 
 add_custom_command(
@@ -134,7 +134,7 @@ install(
 
 install(
     FILES ${CMAKE_CURRENT_BINARY_DIR}/fish.pc
-    DESTINATION ${rel_datadir}/pkgconfig
+    DESTINATION ${rel_datadir}/../libdata/pkgconfig
 )
 
 # CONDEMNED_PAGE is managed by the conditional above
