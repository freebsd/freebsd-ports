--- build/unix/run-mozilla.sh.orig	Wed Oct 23 00:40:21 2002
+++ build/unix/run-mozilla.sh	Wed Oct 23 00:41:01 2002
@@ -355,7 +355,7 @@
 fi
 ##
 ## Set LD_LIBRARY_PATH
-LD_LIBRARY_PATH=${MOZ_DIST_BIN}:${MOZ_DIST_BIN}/plugins:${MRE_HOME}${LD_LIBRARY_PATH+":$LD_LIBRARY_PATH"}
+LD_LIBRARY_PATH=${MOZ_DIST_BIN}:${MOZ_DIST_BIN}/plugins:%%PREFIX%%/lib/browser_plugins:${MRE_HOME}${LD_LIBRARY_PATH+":$LD_LIBRARY_PATH"}
 if [ -n "$LD_LIBRARYN32_PATH" ]
 then
 	LD_LIBRARYN32_PATH=${MOZ_DIST_BIN}:${MOZ_DIST_BIN}/plugins:${MRE_HOME}${LD_LIBRARYN32_PATH+":$LD_LIBRARYN32_PATH"}
@@ -392,7 +392,7 @@
         export XSUNTRANSPORT XSUNSMESIZE
 fi
 # Font path for Xft
-FONTCONFIG_PATH="/etc/fonts:${MOZILLA_FIVE_HOME}/res/Xft"
+FONTCONFIG_PATH="%%PREFIX%%/etc/fonts:${MOZILLA_FIVE_HOME}/res/Xft"
 export FONTCONFIG_PATH
 
 if [ "$moz_debug" -eq 1 ]
@@ -426,6 +426,9 @@
 #
 export MOZILLA_FIVE_HOME LD_LIBRARY_PATH
 export SHLIB_PATH LIBPATH LIBRARY_PATH ADDON_PATH DYLD_LIBRARY_PATH
+
+MOZ_PLUGIN_PATH=%%PREFIX%%/lib/browser_plugins
+export MOZ_PLUGIN_PATH
 
 if [ $moz_debug -eq 1 ]
 then
