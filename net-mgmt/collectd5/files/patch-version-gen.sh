--- version-gen.sh.orig	2019-06-13 09:32:35 UTC
+++ version-gen.sh
@@ -2,10 +2,6 @@
 
 DEFAULT_VERSION="5.9.0.git"
 
-if [ -d .git ]; then
-	VERSION="`git describe --dirty=+ --abbrev=7 2> /dev/null | grep collectd | sed -e 's/^collectd-//' -e 's/-/./g'`"
-fi
-
 if test -z "$VERSION"; then
 	VERSION="$DEFAULT_VERSION"
 fi
