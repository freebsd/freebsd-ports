--- ./src/InstallServer.sh.orig	2011-07-11 15:36:58.000000000 -0400
+++ ./src/InstallServer.sh	2011-10-18 15:26:57.000000000 -0400
@@ -188,7 +188,7 @@
     fi    
 fi
     
-cp -pr ../etc/rules/* ${DIR}/rules/
+cp -pr ../etc/rules/*.xml ${DIR}/rules/
 
 # If the local_rules is saved, moved it back
 ls ${DIR}/rules/saved_local_rules.xml.$$ > /dev/null 2>&1
@@ -307,12 +307,12 @@
 
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
 
 
 
