--- version-gen.sh.orig	2012-04-09 20:04:16.130293641 -0500
+++ version-gen.sh	2012-04-09 20:05:04.927297496 -0500
@@ -1,17 +1,3 @@
-#!/usr/bin/env bash
+#!/bin/sh
 
-DEFAULT_VERSION="5.1.0.git"
-
-VERSION="`git describe 2> /dev/null | sed -e 's/^collectd-//'`"
-
-if test -z "$VERSION"; then
-	VERSION="$DEFAULT_VERSION"
-fi
-
-VERSION="`echo \"$VERSION\" | sed -e 's/-/./g'`"
-
-if test "x`uname -s`" = "xAIX" ; then
-	echo "$VERSION\c"
-else 
-	echo -n "$VERSION"
-fi
+echo -n "5.1.0.git"
