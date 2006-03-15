--- build/unix/run-mozilla.sh.orig	Sat Oct  1 01:36:47 2005
+++ build/unix/run-mozilla.sh	Thu Dec 22 17:51:10 2005
@@ -328,7 +328,7 @@
 fi
 ##
 ## Set LD_LIBRARY_PATH
-LD_LIBRARY_PATH=${MOZ_DIST_BIN}:${MOZ_DIST_BIN}/plugins:${MRE_HOME}${LD_LIBRARY_PATH+":$LD_LIBRARY_PATH"}
+LD_LIBRARY_PATH=${MOZ_DIST_BIN}:%%PREFIX%%/lib/browser_plugins:%%PREFIX%%/lib/browser_linux_plugins:${MOZ_DIST_BIN}/plugins:${MRE_HOME}${LD_LIBRARY_PATH+":$LD_LIBRARY_PATH"}
 if [ -n "$LD_LIBRARYN32_PATH" ]
 then
 	LD_LIBRARYN32_PATH=${MOZ_DIST_BIN}:${MOZ_DIST_BIN}/plugins:${MRE_HOME}${LD_LIBRARYN32_PATH+":$LD_LIBRARYN32_PATH"}
@@ -415,6 +415,9 @@
 #
 export MOZILLA_FIVE_HOME LD_LIBRARY_PATH
 export SHLIB_PATH LIBPATH LIBRARY_PATH ADDON_PATH DYLD_LIBRARY_PATH
+
+MOZ_PLUGIN_PATH=%%PREFIX%%/lib/browser_plugins:%%PREFIX%%/lib/browser_linux_plugins
+export MOZ_PLUGIN_PATH
 
 if [ $moz_debug -eq 1 ]
 then
