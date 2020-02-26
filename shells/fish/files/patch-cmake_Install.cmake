--- cmake/Install.cmake.orig	2020-02-23 21:32:06 UTC
+++ cmake/Install.cmake
@@ -119,7 +119,7 @@ FISH_CREATE_DIRS(${rel_datadir}/fish/vendor_completion
 
 # @echo "Installing pkgconfig file"
 # $v $(INSTALL) -m 644 fish.pc $(DESTDIR)$(datadir)/pkgconfig
-FISH_TRY_CREATE_DIRS(${rel_datadir}/pkgconfig)
+FISH_TRY_CREATE_DIRS(${rel_datadir}/../libdata/pkgconfig)
 CONFIGURE_FILE(fish.pc.in fish.pc.noversion)
 
 ADD_CUSTOM_COMMAND(OUTPUT fish.pc
@@ -132,7 +132,7 @@ ADD_CUSTOM_COMMAND(OUTPUT fish.pc
 ADD_CUSTOM_TARGET(build_fish_pc ALL DEPENDS fish.pc)
 
 INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/fish.pc
-        DESTINATION ${rel_datadir}/pkgconfig)
+        DESTINATION ${rel_datadir}/../libdata/pkgconfig)
 
 # @echo "Installing the $(bo)fish completion library$(sgr0)...";
 # $v $(INSTALL) -m 644 $(COMPLETIONS_DIR_FILES:%='%') $(DESTDIR)$(datadir)/fish/completions/
