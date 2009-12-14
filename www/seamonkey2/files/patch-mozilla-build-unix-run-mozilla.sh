--- mozilla/build/unix/run-mozilla.sh.orig	2009-08-24 19:18:11.000000000 +0200
+++ mozilla/build/unix/run-mozilla.sh	2009-08-24 19:22:10.000000000 +0200
@@ -310,7 +310,7 @@
 }
 if moz_should_set_ld_library_path
 then
-	LD_LIBRARY_PATH=${MOZ_DIST_BIN}:${MOZ_DIST_BIN}/plugins:${MRE_HOME}${LD_LIBRARY_PATH+":$LD_LIBRARY_PATH"}
+	LD_LIBRARY_PATH=${MOZ_DIST_BIN}:%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko18:%%LOCALBASE%%/lib/npapi/symlinks/seamonkey:${MOZ_DIST_BIN}/plugins:${MRE_HOME}${LD_LIBRARY_PATH+":$LD_LIBRARY_PATH"}
 fi 
 
 if [ -n "$LD_LIBRARYN32_PATH" ]
@@ -391,6 +391,9 @@
 export MOZILLA_FIVE_HOME LD_LIBRARY_PATH
 export SHLIB_PATH LIBPATH LIBRARY_PATH ADDON_PATH DYLD_LIBRARY_PATH
 
+MOZ_PLUGIN_PATH=%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko18:%%LOCALBASE%%/lib/npapi/symlinks/seamonkey
+export MOZ_PLUGIN_PATH
+
 if [ $moz_debug -eq 1 ]
 then
 	moz_debug_program ${1+"$@"}
