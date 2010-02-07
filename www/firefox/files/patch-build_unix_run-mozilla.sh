--- build/unix/run-mozilla.sh.orig	Tue Feb 14 19:56:54 2006
+++ build/unix/run-mozilla.sh	Fri Dec  8 15:49:48 2006
@@ -443,6 +443,9 @@
 export MOZILLA_FIVE_HOME LD_LIBRARY_PATH
 export SHLIB_PATH LIBPATH LIBRARY_PATH ADDON_PATH DYLD_LIBRARY_PATH
 
+MOZ_PLUGIN_PATH=%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko19:%%LOCALBASE%%/lib/npapi/symlinks/firefox3
+export MOZ_PLUGIN_PATH
+
 if [ $moz_debug -eq 1 ]
 then
 	moz_debug_program ${1+"$@"}
