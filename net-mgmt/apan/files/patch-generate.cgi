
$FreeBSD$

--- generate.cgi.orig	Fri Mar 26 12:17:34 2004
+++ generate.cgi	Fri Mar 26 12:41:55 2004
@@ -1,4 +1,4 @@
-#!/bin/sh
+#!%%PREFIX%%/bin/bash
 # 
 # This file is used to generate the graphs. It should reside in
 # Nagios cgi-bin directory (Noramally the sbin-dir in your Nagios
@@ -6,7 +6,7 @@
 #
 #
 # Change this if you are not installing apan in /usr/local/nagios/apan
-DEFSFILE=/usr/local/nagios/apan/apan.defs
+DEFSFILE=%%APANCONFDIR%%/apan.defs
 #
 # Don't change anything below...
 #
