--- build/unix/run-mozilla.sh.orig	Thu Oct 17 00:07:52 2002
+++ build/unix/run-mozilla.sh	Thu Oct 17 00:08:24 2002
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
+MOZ_PLUGIN_PATH %%PREFIX%%/lib/browser_plugins
+export MOZ_PLUGIN_PATH
 
 if [ $moz_debug -eq 1 ]
 then
