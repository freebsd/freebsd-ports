--- zap/src/main/dist/zap.sh	2023-07-11 09:00:57.000000000 -0500
+++ zap/src/main/dist/zap.sh	2023-09-18 17:22:08.753719000 -0500
@@ -1,18 +1,7 @@
-#!/usr/bin/env bash
+#!/bin/sh
 
-# Dereference from link to the real directory
-SCRIPTNAME="$0"
+BASEDIR="%%JAVAJARDIR%%/zaproxy"
 
-# While name of this script is symbolic link
-while [ -L "${SCRIPTNAME}" ] ; do
-  cd "`dirname "${SCRIPTNAME}"`" > /dev/null
-  SCRIPTNAME="$(readlink "`basename "${SCRIPTNAME}"`")"
-done
-cd "`dirname "${SCRIPTNAME}"`" > /dev/null
-
-# Base directory where ZAP is installed
-BASEDIR="`pwd -P`"
-
 # Switch to the directory where ZAP is installed
 cd "$BASEDIR"
 
@@ -31,7 +20,7 @@
 fi
 
 # Extract and check the Java version
-JAVA_OUTPUT=$(java -version 2>&1)
+JAVA_OUTPUT=$(%%JAVA_HOME%%/bin/java -version 2>&1)
 
 # Catch warning: Unable to find a $JAVA_HOME at "/usr", continuing with system-provided Java
 if [ "`echo ${JAVA_OUTPUT} | grep "continuing with system-provided Java"`" ] ; then
@@ -43,7 +32,7 @@
 
 DEFAULTJAVAGC=""
 
-JAVA_VERSION=$(java -version 2>&1 | awk -F\" '/version/ { print $2 }')
+JAVA_VERSION=$(%%JAVA_HOME%%/bin/java -version 2>&1 | awk -F\" '/version/ { print $2 }')
 JAVA_MAJOR_VERSION=${JAVA_VERSION%%[.|-]*}
 JAVA_MINOR_VERSION=$(echo $JAVA_VERSION | awk -F\. '{ print $2 }')
 
@@ -90,21 +79,21 @@
   fi
 fi
 
-ARGS=()
+ARGS=""
 for var in "$@"; do
-  if [[ "$var" == -Xmx* ]]; then
+  if [ "$var" == -Xmx* ]; then
     # Overridden by the user
     JMEM="$var"
-  elif [[ $var == --jvmdebug* ]]; then
+  elif [ $var == --jvmdebug* ]; then
 	JAVADEBUGPORT=`echo "$var" | sed -e "s/--jvmdebug//g" | sed -e "s/=//g"`
 	if [ ! "$JAVADEBUGPORT" ]; then
 		JAVADEBUGPORT=1044
 	fi
 	JAVADEBUG="-agentlib:jdwp=transport=dt_socket,server=y,suspend=n,address=127.0.0.1:$JAVADEBUGPORT"
-  elif [[ $var != -psn_* ]]; then
+  elif [ $var != -psn_* ]; then
     # Strip the automatic -psn_x_xxxxxxx argument that OS X automatically passes into apps, since
     # it freaks out ZAP
-    ARGS+=("$var")
+    ARGS=${ARGS}" ${var}"
   fi
 done
 
@@ -121,7 +110,7 @@
 # Start ZAP; it's likely that -Xdock:icon would be ignored on other platforms, but this is known to work
 if [ "$OS" = "Darwin" ]; then
   # It's likely that -Xdock:icon would be ignored on other platforms, but this is known to work
-  exec java ${JMEM} ${JAVAGC} ${JAVADEBUG} -Xdock:icon="../Resources/ZAP.icns" -jar "${BASEDIR}/@zapJar@" "${ARGS[@]}"
+  %%JAVA_HOME%%/bin/java ${JMEM} ${JAVAGC} -Xdock:icon="../Resources/ZAP.icns" -jar "${BASEDIR}/zap-2.11.0.jar" "${ARGS[@]}"
 else
-  exec java ${JMEM} ${JAVAGC} ${JAVADEBUG} -jar "${BASEDIR}/@zapJar@" "${ARGS[@]}"
+  %%JAVA_HOME%%/bin/java ${JMEM} ${JAVAGC} ${JAVADEBUG} -jar "zap-%%VERSION%%.jar" ${ARGS}
 fi
