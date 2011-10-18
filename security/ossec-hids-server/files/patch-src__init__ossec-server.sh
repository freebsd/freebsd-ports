--- ./src/init/ossec-server.sh.orig	2011-07-11 15:36:58.000000000 -0400
+++ ./src/init/ossec-server.sh	2011-10-18 15:26:57.000000000 -0400
@@ -206,7 +206,7 @@
     SDAEMONS="${DB_DAEMON} ${CSYSLOG_DAEMON} ${AGENTLESS_DAEMON} ossec-maild ossec-execd ossec-analysisd ossec-logcollector ossec-remoted ossec-syscheckd ossec-monitord"
     
     echo "Starting $NAME $VERSION (by $AUTHOR)..."
-    echo | ${DIR}/ossec-logtest > /dev/null 2>&1;
+    echo | ${DIR}/bin/ossec-logtest > /dev/null 2>&1;
     if [ ! $? = 0 ]; then
         echo "OSSEC analysisd: Testing rules failed. Configuration error. Exiting."
     fi    
