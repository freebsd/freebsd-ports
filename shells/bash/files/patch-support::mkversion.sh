--- support/mkversion.sh.orig	Tue Oct 12 11:20:53 2004
+++ support/mkversion.sh	Tue Oct 12 11:21:10 2004
@@ -67,7 +67,7 @@
 # increment the build version if that's what's required
 
 if [ -n "$inc_build" ]; then
-	build_ver=`expr $build_ver + 1`
+	build_ver=`expr 1 + $build_ver`
 fi
 
 # what's the patch level?
