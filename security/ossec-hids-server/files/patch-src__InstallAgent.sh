--- src/InstallAgent.sh.orig	2013-10-29 12:13:44.000000000 -0600
+++ src/InstallAgent.sh	2014-06-20 10:30:22.531480743 -0600
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
@@ -107,21 +107,21 @@
 
 # Default for all directories
 chmod -R 550 ${DIR}
-chown -R root:${GROUP} ${DIR}
+#chown -R root:${GROUP} ${DIR}
 
 # To the ossec queue (default for agentd to read)
-chown -R ${USER}:${GROUP} ${DIR}/queue/ossec
+#chown -R ${USER}:${GROUP} ${DIR}/queue/ossec
 chmod -R 770 ${DIR}/queue/ossec
 
 # For the logging user
-chown -R ${USER}:${GROUP} ${DIR}/logs
+#chown -R ${USER}:${GROUP} ${DIR}/logs
 chmod -R 750 ${DIR}/logs
 chmod -R 775 ${DIR}/queue/rids
 touch ${DIR}/logs/ossec.log
-chown ${USER}:${GROUP} ${DIR}/logs/ossec.log
+#chown ${USER}:${GROUP} ${DIR}/logs/ossec.log
 chmod 664 ${DIR}/logs/ossec.log
 
-chown -R ${USER}:${GROUP} ${DIR}/queue/diff
+#chown -R ${USER}:${GROUP} ${DIR}/queue/diff
 chmod -R 750 ${DIR}/queue/diff
 chmod 740 ${DIR}/queue/diff/* > /dev/null 2>&1
 
@@ -130,7 +130,7 @@
 
 # For the etc dir
 chmod 550 ${DIR}/etc
-chown -R root:${GROUP} ${DIR}/etc
+#chown -R root:${GROUP} ${DIR}/etc
 
 ls /etc/localtime > /dev/null 2>&1
 if [ $? = 0 ]; then
@@ -168,12 +168,12 @@
 cp -pr ../etc/client.keys ${DIR}/etc/ > /dev/null 2>&1
 cp -pr agentlessd/scripts/* ${DIR}/agentless/
 
-chown root:${GROUP} ${DIR}/etc/internal_options.conf
-chown root:${GROUP} ${DIR}/etc/local_internal_options.conf > /dev/null 2>&1
-chown root:${GROUP} ${DIR}/etc/client.keys > /dev/null 2>&1
-chown root:${GROUP} ${DIR}/agentless/*
-chown ${USER}:${GROUP} ${DIR}/.ssh
-chown -R root:${GROUP} ${DIR}/etc/shared
+#chown root:${GROUP} ${DIR}/etc/internal_options.conf
+#chown root:${GROUP} ${DIR}/etc/local_internal_options.conf > /dev/null 2>&1
+#chown root:${GROUP} ${DIR}/etc/client.keys > /dev/null 2>&1
+#chown root:${GROUP} ${DIR}/agentless/*
+#chown ${USER}:${GROUP} ${DIR}/.ssh
+#chown -R root:${GROUP} ${DIR}/etc/shared
 
 chmod 550 ${DIR}/etc
 chmod 440 ${DIR}/etc/internal_options.conf
@@ -186,7 +186,7 @@
 
 # For the /var/run
 chmod 770 ${DIR}/var/run
-chown root:${GROUP} ${DIR}/var/run
+#chown root:${GROUP} ${DIR}/var/run
 
 
 # Moving the binary files
@@ -198,7 +198,7 @@
 cp -pr ./init/ossec-client.sh ${DIR}/bin/ossec-control
 cp -pr addagent/manage_agents ${DIR}/bin/
 cp -pr ../contrib/util.sh ${DIR}/bin/
-chown root:${GROUP} ${DIR}/bin/util.sh
+#chown root:${GROUP} ${DIR}/bin/util.sh
 chmod +x ${DIR}/bin/util.sh
 
 # Copying active response modules
@@ -206,9 +206,9 @@
 cp -pr ../active-response/*.sh ${DIR}/active-response/bin/
 cp -pr ../active-response/firewalls/*.sh ${DIR}/active-response/bin/
 chmod 755 ${DIR}/active-response/bin/*
-chown root:${GROUP} ${DIR}/active-response/bin/*
+#chown root:${GROUP} ${DIR}/active-response/bin/*
 
-chown root:${GROUP} ${DIR}/bin/*
+#chown root:${GROUP} ${DIR}/bin/*
 chmod 550 ${DIR}/bin/*
 
 
@@ -223,10 +223,10 @@
 if [ $? = 0 ]; then
     cp -pr ../etc/ossec.mc ${DIR}/etc/ossec.conf
 else    
-    cp -pr ../etc/ossec-agent.conf ${DIR}/etc/ossec.conf
+    cp -pr ../etc/ossec-agent.conf ${DIR}/etc/ossec.conf.sample
 fi
-chown root:${GROUP} ${DIR}/etc/ossec.conf
-chmod 440 ${DIR}/etc/ossec.conf
+#chown root:${GROUP} ${DIR}/etc/ossec.conf.sample
+chmod 440 ${DIR}/etc/ossec.conf.sample
 
 
 
