
$FreeBSD$

--- apan.sh.orig	Fri Mar 26 12:14:40 2004
+++ apan.sh	Fri Mar 26 12:17:04 2004
@@ -1,7 +1,7 @@
-#!/bin/bash
+#!%%PREFIX%%/bin/bash
 
 # Change this if you are not installing apan in /usr/local/nagios/apan
-DEFSFILE=/usr/local/nagios/apan/apan.defs
+DEFSFILE=%%APANCONFDIR%%/apan.defs
 #
 # Don't change anything below...
 #
@@ -66,6 +66,8 @@
 	load) load
 	;;
 	ping) ping
+	;;
+	fping) fping
 	;;
 	lxk_pages) lxk_pages
 	;;
