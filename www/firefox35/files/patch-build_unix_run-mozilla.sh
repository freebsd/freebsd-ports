--- build/unix/run-mozilla.sh.orig	Fri Apr 18 23:12:28 2003
+++ build/unix/run-mozilla.sh	Sat May 31 19:03:29 2003
@@ -355,7 +355,7 @@
 fi
 ##
 ## Set LD_LIBRARY_PATH
-LD_LIBRARY_PATH=${MOZ_DIST_BIN}:${MOZ_DIST_BIN}/plugins:${MRE_HOME}${LD_LIBRARY_PATH+":$LD_LIBRARY_PATH"}
+LD_LIBRARY_PATH=${MOZ_DIST_BIN}:${MOZ_DIST_BIN}/plugins:%%PREFIX%%/lib/browser_plugins:${MRE_HOME}${LD_LIBRARY_PATH+":$LD_LIBRARY_PATH"}
 if [ -n "$LD_LIBRARYN32_PATH" ]
 then
 	LD_LIBRARYN32_PATH=${MOZ_DIST_BIN}:${MOZ_DIST_BIN}/plugins:${MRE_HOME}${LD_LIBRARYN32_PATH+":$LD_LIBRARYN32_PATH"}
@@ -402,7 +402,7 @@
     fi
 fi
 # Font path for Xft
-FONTCONFIG_PATH="/etc/fonts:${MOZILLA_FIVE_HOME}/res/Xft"
+FONTCONFIG_PATH="%%PREFIX%%/etc/fonts:${MOZILLA_FIVE_HOME}/res/Xft"
 export FONTCONFIG_PATH
 
 if [ "$moz_debug" -eq 1 ]
@@ -445,6 +445,9 @@
 #
 export MOZILLA_FIVE_HOME LD_LIBRARY_PATH
 export SHLIB_PATH LIBPATH LIBRARY_PATH ADDON_PATH DYLD_LIBRARY_PATH
+
+MOZ_PLUGIN_PATH=%%PREFIX%%/lib/browser_plugins
+export MOZ_PLUGIN_PATH
 
 if [ $moz_debug -eq 1 ]
 then
