$FreeBSD$

--- build/unix/run-mozilla.sh.orig	Mon Dec 15 12:27:28 2003
+++ build/unix/run-mozilla.sh	Wed Feb 11 14:24:17 2004
@@ -355,7 +355,7 @@
 fi
 ##
 ## Set LD_LIBRARY_PATH
-LD_LIBRARY_PATH=${MOZ_DIST_BIN}:${MOZ_DIST_BIN}/plugins:${MRE_HOME}${LD_LIBRARY_PATH+":$LD_LIBRARY_PATH"}
+LD_LIBRARY_PATH=${MOZ_DIST_BIN}:${MOZ_DIST_BIN}/plugins:%%PREFIX%%/lib/browser_plugins:${MRE_HOME}${LD_LIBRARY_PATH+":$LD_LIBRARY_PATH"}
 if [ -n "$LD_LIBRARYN32_PATH" ]
 then
 	LD_LIBRARYN32_PATH=${MOZ_DIST_BIN}:${MOZ_DIST_BIN}/plugins:${MRE_HOME}${LD_LIBRARYN32_PATH+":$LD_LIBRARYN32_PATH"}
@@ -442,6 +442,9 @@
 #
 export MOZILLA_FIVE_HOME LD_LIBRARY_PATH
 export SHLIB_PATH LIBPATH LIBRARY_PATH ADDON_PATH DYLD_LIBRARY_PATH
+
+MOZ_PLUGIN_PATH=%%PREFIX%%/lib/browser_plugins
+export MOZ_PLUGIN_PATH
 
 if [ $moz_debug -eq 1 ]
 then
