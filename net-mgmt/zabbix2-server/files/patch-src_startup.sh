--- src/zabbix_java/startup.sh.orig	2013-11-12 10:07:23.000000000 +0400
+++ src/zabbix_java/startup.sh	2013-12-04 16:37:05.000000000 +0400
@@ -1,7 +1,7 @@
-#!/bin/bash
+#!/bin/sh
 
 cd $(dirname $0)
-source settings.sh
+. settings.sh
 
 if [ -n "$PID_FILE" -a -e "$PID_FILE" ]; then
 	echo "Zabbix Java Gateway is already running"
@@ -16,8 +16,8 @@
 fi
 
 CLASSPATH="lib"
-for jar in {lib,bin}/*.jar; do
-	if [[ $jar != *junit* ]]; then
+for jar in lib/*.jar bin/*.jar; do
+	if [ "$jar" != "*junit*" ]; then
 		CLASSPATH="$CLASSPATH:$jar"
 	fi
 done
@@ -39,7 +39,7 @@
 COMMAND_LINE="$JAVA $JAVA_OPTIONS -classpath $CLASSPATH $ZABBIX_OPTIONS com.zabbix.gateway.JavaGateway"
 
 if [ -n "$PID_FILE" ]; then
-	PID=$(/bin/bash -c "$COMMAND_LINE > /dev/null 2>&1 & echo \$!")
+	PID=$(/bin/sh -c "$COMMAND_LINE > /dev/null 2>&1 & echo \$!")
 	if ps -p $PID > /dev/null 2>&1; then
 		echo $PID > $PID_FILE
 	else
