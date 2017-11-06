--- version-gen.sh.orig	2017-02-03 20:46:49 UTC
+++ version-gen.sh
@@ -2,10 +2,6 @@
 
 DEFAULT_VERSION="5.7.1.git"
 
-if [ -d .git ]; then
-	VERSION="`git describe --dirty=+ --abbrev=7 2> /dev/null | grep collectd | sed -e 's/^collectd-//' -e 's/-/./g'`"
-fi
-
 if test -z "$VERSION"; then
 	VERSION="$DEFAULT_VERSION"
 fi
