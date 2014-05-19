--- ./src/InstallAgent.sh.orig	2013-10-29 12:13:44.000000000 -0600
+++ ./src/InstallAgent.sh	2014-05-16 07:12:31.133178776 -0600
@@ -37,11 +37,11 @@
 
 # Creating groups/users
 if [ "$UNAME" = "FreeBSD" -o "$UNAME" = "DragonFly" ]; then
-    grep "^${USER}" /etc/passwd > /dev/null 2>&1
-    if [ ! $? = 0 ]; then
-    /usr/sbin/pw groupadd ${GROUP}
-	/usr/sbin/pw useradd ${USER} -d ${DIR} -s /sbin/nologin -g ${GROUP}
-    fi
+#    grep "^${USER}" /etc/passwd > /dev/null 2>&1
+#    if [ ! $? = 0 ]; then
+#    /usr/sbin/pw groupadd ${GROUP}
+#	/usr/sbin/pw useradd ${USER} -d ${DIR} -s /sbin/nologin -g ${GROUP}
+#    fi
 
 elif [ "$UNAME" = "SunOS" ]; then
     grep "^${USER}" /etc/passwd > /dev/null 2>&1
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
 
 
 
