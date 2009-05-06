--- build/unix/run-mozilla.sh.orig	2007-09-05 02:18:08.000000000 +0200
+++ build/unix/run-mozilla.sh	2009-04-20 23:17:23.000000000 +0200
@@ -353,7 +353,7 @@
 ##  a symbolic link, all other shared libraries are symbolic links also.
 if [ `uname -s` != "SunOS" -o -h "$MOZ_DIST_BIN/libmozjs.so" ]
 then
-	LD_LIBRARY_PATH=${MOZ_DIST_BIN}:${MOZ_DIST_BIN}/plugins:${MRE_HOME}${LD_LIBRARY_PATH+":$LD_LIBRARY_PATH"}
+	LD_LIBRARY_PATH=${MOZ_DIST_BIN}:${MOZ_DIST_BIN}/plugins:%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko19:%%LOCALBASE%%/lib/npapi/symlinks/flock:${MRE_HOME}${LD_LIBRARY_PATH+":$LD_LIBRARY_PATH"}
 fi 
 
 if [ -n "$LD_LIBRARYN32_PATH" ]
@@ -434,6 +434,9 @@
 export MOZILLA_FIVE_HOME LD_LIBRARY_PATH
 export SHLIB_PATH LIBPATH LIBRARY_PATH ADDON_PATH DYLD_LIBRARY_PATH
 
+MOZ_PLUGIN_PATH=%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko18:%%LOCALBASE%%/lib/npapi/symlinks/flock
+export MOZ_PLUGIN_PATH
+
 if [ $moz_debug -eq 1 ]
 then
 	moz_debug_program ${1+"$@"}
