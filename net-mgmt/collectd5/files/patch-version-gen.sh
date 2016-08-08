--- version-gen.sh.orig	2016-08-05 21:19:57 UTC
+++ version-gen.sh
@@ -1,13 +1,3 @@
 #!/bin/sh
 
-DEFAULT_VERSION="5.5.2.git"
-
-VERSION="`git describe 2> /dev/null | grep collectd | sed -e 's/^collectd-//'`"
-
-if test -z "$VERSION"; then
-	VERSION="$DEFAULT_VERSION"
-fi
-
-VERSION="`echo \"$VERSION\" | sed -e 's/-/./g'`"
-
-printf "%s" "$VERSION"
+echo -n '5.5.2.git'
