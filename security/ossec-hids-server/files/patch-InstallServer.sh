diff -ruN src/InstallServer.sh.orig src/InstallServer.sh
--- src/InstallServer.sh.orig	Sun Jan  7 23:38:16 2007
+++ src/InstallServer.sh	Thu Apr  5 15:58:08 2007
@@ -255,12 +255,12 @@
 
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
 
 
 
