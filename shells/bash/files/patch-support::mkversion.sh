--- support/mkversion.sh.orig	Sat Sep 11 11:08:31 2004
+++ support/mkversion.sh	Wed Dec 28 20:15:34 2005
@@ -67,7 +67,7 @@
 # increment the build version if that's what's required
 
 if [ -n "$inc_build" ]; then
-	build_ver=`expr $build_ver + 1`
+	build_ver=`expr 1 + $build_ver`
 fi
 
 # what's the patch level?
