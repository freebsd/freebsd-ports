--- cmake/Install.cmake.orig	2018-12-29 16:18:12 UTC
+++ cmake/Install.cmake
@@ -113,7 +113,7 @@ INSTALL(FILES share/config.fish
 # -$v $(INSTALL) -m 755 -d $(DESTDIR)$(extra_completionsdir)
 # -$v $(INSTALL) -m 755 -d $(DESTDIR)$(extra_functionsdir)
 # -$v $(INSTALL) -m 755 -d $(DESTDIR)$(extra_confdir)
-FISH_CREATE_DIRS(${rel_datadir}/pkgconfig)
+FISH_CREATE_DIRS(${rel_datadir}/../libdata/pkgconfig)
 # Don't try too hard to create these directories as they may be outside our writeable area
 # https://github.com/Homebrew/homebrew-core/pull/2813
 FISH_TRY_CREATE_DIRS(${extra_completionsdir} ${extra_functionsdir} ${extra_confdir})
@@ -132,7 +132,7 @@ ADD_CUSTOM_COMMAND(OUTPUT fish.pc
 ADD_CUSTOM_TARGET(build_fish_pc ALL DEPENDS fish.pc)
 
 INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/fish.pc
-        DESTINATION ${rel_datadir}/pkgconfig)
+        DESTINATION ${rel_datadir}/../libdata/pkgconfig)
 
 # @echo "Installing the $(bo)fish completion library$(sgr0)...";
 # $v $(INSTALL) -m 644 $(COMPLETIONS_DIR_FILES:%='%') $(DESTDIR)$(datadir)/fish/completions/
