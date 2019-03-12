--- cmake/Install.cmake.orig	2019-02-19 13:39:17 UTC
+++ cmake/Install.cmake
@@ -53,9 +53,7 @@ ENDIF()
 # Define a function to help us create directories.
 FUNCTION(FISH_CREATE_DIRS)
   FOREACH(dir ${ARGV})
-      IF(NOT EXISTS ${CMAKE_INSTALL_PREFIX}/${dir})
-        INSTALL(DIRECTORY DESTINATION ${dir})
-      ENDIF()
+    INSTALL(DIRECTORY DESTINATION ${dir})
   ENDFOREACH(dir)
 ENDFUNCTION(FISH_CREATE_DIRS)
 
@@ -113,9 +111,9 @@ INSTALL(FILES share/config.fish
 # -$v $(INSTALL) -m 755 -d $(DESTDIR)$(extra_completionsdir)
 # -$v $(INSTALL) -m 755 -d $(DESTDIR)$(extra_functionsdir)
 # -$v $(INSTALL) -m 755 -d $(DESTDIR)$(extra_confdir)
-FISH_CREATE_DIRS(${rel_datadir}/pkgconfig)
 # Don't try too hard to create these directories as they may be outside our writeable area
 # https://github.com/Homebrew/homebrew-core/pull/2813
+FISH_TRY_CREATE_DIRS(${rel_datadir}/../libdata/pkgconfig)
 FISH_TRY_CREATE_DIRS(${extra_completionsdir} ${extra_functionsdir} ${extra_confdir})
 
 # @echo "Installing pkgconfig file"
@@ -132,7 +130,7 @@ ADD_CUSTOM_COMMAND(OUTPUT fish.pc
 ADD_CUSTOM_TARGET(build_fish_pc ALL DEPENDS fish.pc)
 
 INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/fish.pc
-        DESTINATION ${rel_datadir}/pkgconfig)
+        DESTINATION ${rel_datadir}/../libdata/pkgconfig)
 
 # @echo "Installing the $(bo)fish completion library$(sgr0)...";
 # $v $(INSTALL) -m 644 $(COMPLETIONS_DIR_FILES:%='%') $(DESTDIR)$(datadir)/fish/completions/
