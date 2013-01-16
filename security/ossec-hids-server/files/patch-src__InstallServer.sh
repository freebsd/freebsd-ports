--- ./src/InstallServer.sh.orig	2012-11-08 21:24:55.000000000 -0500
+++ ./src/InstallServer.sh	2013-01-14 10:44:36.000000000 -0500
@@ -195,7 +195,7 @@
     fi    
 fi
     
-cp -pr ../etc/rules/* ${DIR}/rules/
+cp -pr ../etc/rules/*.xml ${DIR}/rules/
 find ${DIR}/rules/ -type f -exec chmod 440 {} \;
 
 # If the local_rules is saved, moved it back
@@ -318,12 +318,12 @@
 
 ls ../etc/ossec.mc > /dev/null 2>&1
 if [ $? = 0 ]; then
-    cp -pr ../etc/ossec.mc ${DIR}/etc/ossec.conf
+    cp -pr ../etc/ossec.mc ${DIR}/etc/ossec.conf.sample
 else    
-    cp -pr ../etc/ossec-server.conf ${DIR}/etc/ossec.conf
+    cp -pr ../etc/ossec-server.conf ${DIR}/etc/ossec.conf.sample
 fi
-chown root:${GROUP} ${DIR}/etc/ossec.conf
-chmod 440 ${DIR}/etc/ossec.conf
+chown root:${GROUP} ${DIR}/etc/ossec.conf.sample
+chmod 440 ${DIR}/etc/ossec.conf.sample
 
 
 
