$FreeBSD$

--- /dev/null	2011-04-19 17:01:32.000000000 -0700
+++ init.sh	2011-04-19 17:02:19.000000000 -0700
@@ -0,0 +1,19 @@
+#!/usr/bin/env bash
+# load up the functions we'll use to build and install
+. shared-functions.sh
+. build-functions.sh
+
+# gracefully handle Ctrl-C or other interrupts
+trap cleanup EXIT
+
+if [ "`whoami`" != "zenoss" ]; then
+   echo "You must run this script as the zenoss user"
+   exit 1
+fi
+
+if [ ! -f "$ZENHOME/etc/zope.conf" ]; then
+   cp -p $ZENHOME/etc/zope.conf.in $ZENHOME/etc/zope.conf
+fi
+
+init
+get_happy
