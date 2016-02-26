--- tools/firmware/seabios-dir/scripts/buildversion.sh.orig	2015-03-13 09:02:17 UTC
+++ tools/firmware/seabios-dir/scripts/buildversion.sh
@@ -12,7 +12,7 @@ if [ -z "$BUILD_VERSION" ]; then
     else
         VERSION="?"
     fi
-    VERSION="${VERSION}-`date +"%Y%m%d_%H%M%S"`-`hostname`"
+    VERSION="${VERSION}"
 else
     VERSION="$BUILD_VERSION"
 fi
