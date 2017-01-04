--- version-gen.sh.orig	2017-01-03 08:18:24.963614000 -0500
+++ version-gen.sh	2017-01-03 08:19:07.743161000 -0500
@@ -1,13 +1,2 @@
 #!/bin/sh
-
-DEFAULT_VERSION="5.7.0.git"
-
-if [ -d .git ]; then
-	VERSION="`git describe --dirty=+ --abbrev=7 2> /dev/null | grep collectd | sed -e 's/^collectd-//' -e 's/-/./g'`"
-fi
-
-if test -z "$VERSION"; then
-	VERSION="$DEFAULT_VERSION"
-fi
-
-printf "%s" "$VERSION"
+echo -n '5.7.0.git'
