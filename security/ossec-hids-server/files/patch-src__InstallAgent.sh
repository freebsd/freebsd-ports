--- src/InstallAgent.sh.orig	2014-05-15 09:23:09.596592731 -0600
+++ src/InstallAgent.sh	2014-05-15 09:23:33.770590120 -0600
@@ -223,10 +223,10 @@
 if [ $? = 0 ]; then
     cp -pr ../etc/ossec.mc ${DIR}/etc/ossec.conf
 else    
-    cp -pr ../etc/ossec-agent.conf ${DIR}/etc/ossec.conf
+    cp -pr ../etc/ossec-agent.conf ${DIR}/etc/ossec.conf.sample
 fi
-chown root:${GROUP} ${DIR}/etc/ossec.conf
-chmod 440 ${DIR}/etc/ossec.conf
+chown root:${GROUP} ${DIR}/etc/ossec.conf.sample
+chmod 440 ${DIR}/etc/ossec.conf.sample
 
 
 
