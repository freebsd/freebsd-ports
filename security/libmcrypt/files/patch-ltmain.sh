--- ltmain.sh.orig	Fri Feb  1 20:23:29 2002
+++ ltmain.sh	Sat Mar  2 15:26:31 2002
@@ -958,6 +958,7 @@
 	;;
 
       -avoid-version)
+	build_old_libs=no
 	avoid_version=yes
 	continue
 	;;
