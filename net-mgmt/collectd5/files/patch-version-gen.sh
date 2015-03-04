--- version-gen.sh.orig	2015-03-02 20:20:43 UTC
+++ version-gen.sh
@@ -1,13 +1,3 @@
-#!/usr/bin/env bash
-
-DEFAULT_VERSION="5.4.2.git"
-
-VERSION="`git describe 2> /dev/null | sed -e 's/^collectd-//'`"
-
-if test -z "$VERSION"; then
-	VERSION="$DEFAULT_VERSION"
-fi
-
-VERSION="`echo \"$VERSION\" | sed -e 's/-/./g'`"
+#!/bin/sh
 
-echo -n "$VERSION"
+echo -n "5.4.2.git"
