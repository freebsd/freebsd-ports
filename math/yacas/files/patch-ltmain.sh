--- ltmain.sh.orig	Mon Mar 10 05:53:57 2003
+++ ltmain.sh	Wed May 21 14:17:14 2003
@@ -973,6 +973,7 @@
 	;;
 
       -avoid-version)
+	build_old_libs=no
 	avoid_version=yes
 	continue
 	;;
