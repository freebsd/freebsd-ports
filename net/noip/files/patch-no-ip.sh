--- no-ip.sh.orig	Wed Oct 10 16:35:12 2001
+++ no-ip.sh	Fri Mar 29 01:55:11 2002
@@ -1,3 +1,4 @@
+#!/bin/sh
 #
 # configuration file builder script for no-ip
 #
@@ -89,7 +90,7 @@
 #
 if [ "$NAT" = "N" ] 
 then
-    devs=`tail +3 /proc/net/dev | awk -F: '{print $1}' | tr -d ' '|tr '\n' ' '`
+    devs=`ifconfig -l inet`
     DEV=foo
     while [ "$DEV" = "foo" ]
     do
