--- pipsecd.sh.orig	2015-02-27 22:18:20 UTC
+++ pipsecd.sh
@@ -0,0 +1,2 @@
+#!/bin/sh
+cd /usr/local; [ -x sbin/pipsecd -a -f etc/ipsec/pipsecd.conf ] && sbin/pipsecd & && echo -n ' pipsecd'
