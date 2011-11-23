--- ./src/init/ossec-local.sh.orig	2011-11-23 15:37:30.000000000 -0500
+++ ./src/init/ossec-local.sh	2011-11-23 15:37:39.000000000 -0500
@@ -207,7 +207,7 @@
     SDAEMONS="${DB_DAEMON} ${CSYSLOG_DAEMON} ${AGENTLESS_DAEMON} ossec-maild ossec-execd ossec-analysisd ossec-logcollector ossec-syscheckd ossec-monitord"
     
     echo "Starting $NAME $VERSION (by $AUTHOR)..."
-    echo | ${DIR}/ossec-logtest > /dev/null 2>&1;
+    echo | ${DIR}/bin/ossec-logtest > /dev/null 2>&1;
     if [ ! $? = 0 ]; then
         echo "ossec-analysisd: Configuration error. Exiting."
     fi    
