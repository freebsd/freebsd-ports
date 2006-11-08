--- ltmain.sh.orig	Fri Oct 27 22:47:02 2006
+++ ltmain.sh	Tue Nov  7 10:33:04 2006
@@ -1256,6 +1256,7 @@
 	;;
 
       -avoid-version)
+      	build_old_libs=no
 	avoid_version=yes
 	continue
 	;;
