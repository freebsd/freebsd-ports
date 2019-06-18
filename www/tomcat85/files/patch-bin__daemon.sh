--- bin/daemon.sh.orig
+++ bin/daemon.sh
@@ -115,12 +115,9 @@
 test ".$CATALINA_HOME" = . && CATALINA_HOME=`cd "$DIRNAME/.." >/dev/null; pwd`
 test ".$CATALINA_BASE" = . && CATALINA_BASE="$CATALINA_HOME"
 test ".$CATALINA_MAIN" = . && CATALINA_MAIN=org.apache.catalina.startup.Bootstrap
-# If not explicitly set, look for jsvc in CATALINA_BASE first then CATALINA_HOME
+# If not explicitly set, look for jsvc in %%PREFIX%%
 if [ -z "$JSVC" ]; then
-    JSVC="$CATALINA_BASE/bin/jsvc"
-    if [ ! -x "$JSVC" ]; then
-        JSVC="$CATALINA_HOME/bin/jsvc"
-    fi
+    JSVC="%%PREFIX%%/bin/jsvc"
 fi
 # Set the default service-start wait time if necessary
 test ".$SERVICE_START_WAIT_TIME" = . && SERVICE_START_WAIT_TIME=10
@@ -137,7 +134,7 @@
 
 # Add on extra jar files to CLASSPATH
 test ".$CLASSPATH" != . && CLASSPATH="$CLASSPATH:"
-CLASSPATH="$CLASSPATH$CATALINA_HOME/bin/bootstrap.jar:$CATALINA_HOME/bin/commons-daemon.jar"
+CLASSPATH="$CLASSPATH$CATALINA_HOME/bin/bootstrap.jar:%%JAVAJARDIR%%/commons-daemon.jar"
 
 test ".$CATALINA_OUT" = . && CATALINA_OUT="$CATALINA_BASE/logs/catalina-daemon.out"
 test ".$CATALINA_TMP" = . && CATALINA_TMP="$CATALINA_BASE/temp"
