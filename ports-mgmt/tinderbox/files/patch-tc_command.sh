--- lib/tc_command.sh_ori	2009-09-17 15:36:34.000000000 +0200
+++ lib/tc_command.sh	2009-09-17 15:36:40.000000000 +0200
@@ -1649,7 +1649,7 @@
     # Set up the chrooted environment
     osmajor=$(echo ${jail} | sed -E -e 's|(^[[:digit:]]+).*$|\1|')
     case ${osmajor} in
-    6|7|8)	tinderbuild_setup;;
+    6|7|8|9)	tinderbuild_setup;;
     *)		echo "tinderbuild: unhandled OS version: ${osmajor}"
 		tinderbuild_cleanup 1
 		;;
