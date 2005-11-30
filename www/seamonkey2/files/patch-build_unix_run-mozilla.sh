--- build/unix/run-mozilla.sh.orig	Mon Oct 17 13:21:17 2005
+++ build/unix/run-mozilla.sh	Thu Nov 10 22:01:41 2005
@@ -333,7 +333,7 @@
 ## LD_LIBRARY_PATH because $ORIGIN doesn't work on a symbolic link.
 if [ `uname -s` != "SunOS" -o -h "$MOZ_PROGRAM" ]
 then
-	LD_LIBRARY_PATH=${MOZ_DIST_BIN}:${MOZ_DIST_BIN}/plugins:${MRE_HOME}${LD_LIBRARY_PATH+":$LD_LIBRARY_PATH"}
+	LD_LIBRARY_PATH=${MOZ_DIST_BIN}:${MOZ_DIST_BIN}/plugins:%%PREFIX%%/lib/browser_plugins:%%PREFIX%%/lib/browser_linux_plugins:${MRE_HOME}${LD_LIBRARY_PATH+":$LD_LIBRARY_PATH"}
 fi 
 
 if [ -n "$LD_LIBRARYN32_PATH" ]
@@ -422,6 +422,9 @@
 #
 export MOZILLA_FIVE_HOME LD_LIBRARY_PATH
 export SHLIB_PATH LIBPATH LIBRARY_PATH ADDON_PATH DYLD_LIBRARY_PATH
+
+MOZ_PLUGIN_PATH=%%PREFIX%%/lib/browser_plugins:%%PREFIX%%/lib/browser_linux_plugins
+export MOZ_PLUGIN_PATH
 
 if [ $moz_debug -eq 1 ]
 then
