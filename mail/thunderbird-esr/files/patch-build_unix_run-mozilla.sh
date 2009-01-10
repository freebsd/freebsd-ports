--- build/unix/run-mozilla.sh.orig	Mon Dec 15 18:27:28 2003
+++ build/unix/run-mozilla.sh	Fri Feb 27 11:54:10 2004
@@ -355,7 +355,7 @@
 fi
 ##
 ## Set LD_LIBRARY_PATH
-LD_LIBRARY_PATH=${MOZ_DIST_BIN}:${MOZ_DIST_BIN}/plugins:${MRE_HOME}${LD_LIBRARY_PATH+":$LD_LIBRARY_PATH"}
+LD_LIBRARY_PATH=${MOZ_DIST_BIN}:${MOZ_DIST_BIN}/plugins:%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko18:%%LOCALBASE%%/lib/npapi/symlinks/thunderbird:${MRE_HOME}${LD_LIBRARY_PATH+":$LD_LIBRARY_PATH"}
 if [ -n "$LD_LIBRARYN32_PATH" ]
 then
 	LD_LIBRARYN32_PATH=${MOZ_DIST_BIN}:${MOZ_DIST_BIN}/plugins:${MRE_HOME}${LD_LIBRARYN32_PATH+":$LD_LIBRARYN32_PATH"}
