--- src/InstallServer.sh	2008-08-22 20:42:09.000000000 +0000
+++ src/InstallServer.sh	2008-09-28 22:10:45.000000000 +0000
@@ -174,7 +174,7 @@
     fi    
 fi
     
-cp -pr ../etc/rules/* ${DIR}/rules/
+cp -pr ../etc/rules/*.xml ${DIR}/rules/
 
 # If the local_rules is saved, moved it back
 ls ${DIR}/rules/saved_local_rules.xml.$$ > /dev/null 2>&1
@@ -284,12 +284,12 @@
 
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
 
 
 
