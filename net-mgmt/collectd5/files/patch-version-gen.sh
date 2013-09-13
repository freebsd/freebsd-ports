--- version-gen.sh.orig	2013-08-19 10:57:47.000000000 -0600
+++ version-gen.sh	2013-08-19 10:58:15.000000000 -0600
@@ -1,13 +1,3 @@
-#!/usr/bin/env bash
+#!/bin/sh
 
-DEFAULT_VERSION="5.4.0.git"
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
+echo -n '5.4.0.git'
