--- runme.sh.orig	Thu Apr  3 17:31:40 2003
+++ runme.sh	Thu Apr  3 18:36:09 2003
@@ -177,7 +177,7 @@
 export OPERA_DIR OPERA_PLUGIN_PATH
 
 # Running Opera
-${OPERA} "${@}"
+exec ${OPERA} "${@}"
 
 # Cleanup
 if test "${_CLEAN_OPERA_POLICY_}" = 'YES'; then
