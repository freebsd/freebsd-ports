diff --git version-gen.sh version-gen.sh
index e344541..1ed7480 100755
--- version-gen.sh
+++ version-gen.sh
@@ -1,13 +1,3 @@
-#!/usr/bin/env bash
+#!/bin/sh
 
-DEFAULT_VERSION="5.2.1.git"
-
-VERSION="`git describe 2> /dev/null | sed -e 's/^collectd-//'`"
-
-if test -z "$VERSION"; then
-	VERSION="$DEFAULT_VERSION"
-fi
-
-VERSION="`echo \"$VERSION\" | sed -e 's/-/./g'`"
-
-echo -n "$VERSION"
+echo -n "5.2.1.git"
