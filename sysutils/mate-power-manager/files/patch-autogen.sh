--- autogen.sh.orig	2013-10-19 11:55:08.000000000 +0200
+++ autogen.sh	2013-10-19 11:55:03.000000000 +0200
@@ -0,0 +1,24 @@
+#!/bin/sh
+# Run this to generate all the initial makefiles, etc.
+
+srcdir=`dirname $0`
+test -z "$srcdir" && srcdir=.
+
+PKG_NAME="mate-power-manager"
+
+(test -f $srcdir/configure.ac) || {
+    echo -n "**Error**: Directory "\`$srcdir\'" does not look like the"
+    echo " top-level $PKG_NAME directory"
+    exit 1
+}
+
+which mate-autogen || {
+    echo "You need to install mate-common from the MATE Git"
+    exit 1
+}
+
+REQUIRED_AUTOMAKE_VERSION=1.9
+MATE_DATADIR="$mate_datadir"
+
+. mate-autogen
+
