--- version-gen.sh.orig	2014-01-26 12:09:23.540560000 +0400
+++ version-gen.sh	2014-04-06 14:44:48.000000000 +0400
@@ -1,13 +1,3 @@
-#!/usr/bin/env bash
+#!/bin/sh
 
-DEFAULT_VERSION="5.4.1.git"
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
+echo -n "5.4.1.git"
