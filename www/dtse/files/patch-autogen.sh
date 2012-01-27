--- ./autogen.sh.orig	2011-12-30 17:37:16.000000000 -0800
+++ ./autogen.sh	2011-12-30 17:37:16.000000000 -0800
@@ -0,0 +1,14 @@
+#!/bin/sh
+#
+# Douglas Thrift's Search Engine
+#
+# Douglas Thrift
+#
+# $Id$
+
+set -e
+cd `dirname $0`
+
+aclocal
+automake -acf || true
+autoconf
