$FreeBSD$

--- build/unix/run-mozilla.sh.orig	Mon Feb  9 19:25:14 2004
+++ build/unix/run-mozilla.sh	Mon Feb  9 21:18:11 2004
@@ -355,7 +355,7 @@
 fi
 ##
 ## Set LD_LIBRARY_PATH
-LD_LIBRARY_PATH=${MOZ_DIST_BIN}:${MOZ_DIST_BIN}/plugins:${MRE_HOME}${LD_LIBRARY_PATH+":$LD_LIBRARY_PATH"}
+LD_LIBRARY_PATH=${MOZ_DIST_BIN}:${MOZ_DIST_BIN}/plugins:%PREFIX%%/lib/browser_plugins:${MRE_HOME}${LD_LIBRARY_PATH+":$LD_LIBRARY_PATH"}
 if [ -n "$LD_LIBRARYN32_PATH" ]
 then
 	LD_LIBRARYN32_PATH=${MOZ_DIST_BIN}:${MOZ_DIST_BIN}/plugins:${MRE_HOME}${LD_LIBRARYN32_PATH+":$LD_LIBRARYN32_PATH"}
