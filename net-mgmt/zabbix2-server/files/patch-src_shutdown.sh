--- src/zabbix_java/shutdown.sh.orig	2013-11-12 10:07:23.000000000 +0400
+++ src/zabbix_java/shutdown.sh	2013-12-04 16:37:38.000000000 +0400
@@ -1,7 +1,7 @@
-#!/bin/bash
+#!/bin/sh
 
 cd $(dirname $0)
-source settings.sh
+. settings.sh
 
 if [ -n "$PID_FILE" ]; then
 	if [ -e "$PID_FILE" ]; then
