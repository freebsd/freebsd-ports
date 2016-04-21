--- src/InstallAgent.sh.orig	2015-10-12 21:21:06 UTC
+++ src/InstallAgent.sh
@@ -37,11 +37,11 @@ fi
 
 # Creating groups/users
 if [ "$UNAME" = "FreeBSD" -o "$UNAME" = "DragonFly" ]; then
-    grep "^${USER}" /etc/passwd > /dev/null 2>&1
-    if [ ! $? = 0 ]; then
-    /usr/sbin/pw groupadd ${GROUP}
-	/usr/sbin/pw useradd ${USER} -d ${DIR} -s /sbin/nologin -g ${GROUP}
-    fi
+    #grep "^${USER}" /etc/passwd > /dev/null 2>&1
+    #if [ ! $? = 0 ]; then
+    #/usr/sbin/pw groupadd ${GROUP}
+	#/usr/sbin/pw useradd ${USER} -d ${DIR} -s /sbin/nologin -g ${GROUP}
+    #fi
 
 elif [ "$UNAME" = "SunOS" ]; then
     grep "^${USER}" /etc/passwd > /dev/null 2>&1
@@ -106,22 +106,17 @@ for i in ${subdirs}; do
 done
 
 # Default for all directories
-chmod -R 550 ${DIR}
-chown -R root:${GROUP} ${DIR}
+chmod -R 750 ${DIR}
 
 # To the ossec queue (default for agentd to read)
-chown -R ${USER}:${GROUP} ${DIR}/queue/ossec
 chmod -R 770 ${DIR}/queue/ossec
 
 # For the logging user
-chown -R ${USER}:${GROUP} ${DIR}/logs
 chmod -R 750 ${DIR}/logs
 chmod -R 775 ${DIR}/queue/rids
 touch ${DIR}/logs/ossec.log
-chown ${USER}:${GROUP} ${DIR}/logs/ossec.log
 chmod 664 ${DIR}/logs/ossec.log
 
-chown -R ${USER}:${GROUP} ${DIR}/queue/diff
 chmod -R 750 ${DIR}/queue/diff
 chmod 740 ${DIR}/queue/diff/* > /dev/null 2>&1
 
@@ -131,8 +126,7 @@ chmod 1550 ${DIR}/tmp
 
 
 # For the etc dir
-chmod 550 ${DIR}/etc
-chown -R root:${GROUP} ${DIR}/etc
+chmod 750 ${DIR}/etc
 
 ls /etc/localtime > /dev/null 2>&1
 if [ $? = 0 ]; then
@@ -144,13 +138,11 @@ if [ "$UNAME" = "SunOS" ]; then
     mkdir -p ${DIR}/usr/share/lib/zoneinfo/
     chmod -R 555 ${DIR}/usr/
     cp -pr /usr/share/lib/zoneinfo/* ${DIR}/usr/share/lib/zoneinfo/
-    chown -R root:${GROUP} ${DIR}/usr/
 fi    
 
 ls /etc/TIMEZONE > /dev/null 2>&1
 if [ $? = 0 ]; then
     cp -p /etc/TIMEZONE ${DIR}/etc/;
-    chown root:${GROUP} ${DIR}/etc/TIMEZONE
     chmod 555 ${DIR}/etc/TIMEZONE
 fi
             
@@ -170,25 +162,17 @@ cp -pr ../etc/local_internal_options.con
 cp -pr ../etc/client.keys ${DIR}/etc/ > /dev/null 2>&1
 cp -pr agentlessd/scripts/* ${DIR}/agentless/
 
-chown root:${GROUP} ${DIR}/etc/internal_options.conf
-chown root:${GROUP} ${DIR}/etc/local_internal_options.conf > /dev/null 2>&1
-chown root:${GROUP} ${DIR}/etc/client.keys > /dev/null 2>&1
-chown root:${GROUP} ${DIR}/agentless/*
-chown ${USER}:${GROUP} ${DIR}/.ssh
-chown -R root:${GROUP} ${DIR}/etc/shared
-
-chmod 550 ${DIR}/etc
+chmod 750 ${DIR}/etc
 chmod 440 ${DIR}/etc/internal_options.conf
 chmod 440 ${DIR}/etc/local_internal_options.conf > /dev/null 2>&1
 chmod 440 ${DIR}/etc/client.keys > /dev/null 2>&1
 chmod -R 770 ${DIR}/etc/shared # ossec must be able to write to it
-chmod 550 ${DIR}/agentless/*
+chmod 750 ${DIR}/agentless/*
 chmod 700 ${DIR}/.ssh
 
 
 # For the /var/run
 chmod 770 ${DIR}/var/run
-chown root:${GROUP} ${DIR}/var/run
 
 
 # Moving the binary files
@@ -202,7 +186,6 @@ cp -pr addagent/manage_agents ${DIR}/bin
 cp -pr ../contrib/util.sh ${DIR}/bin/
 cp -pr external/lua/src/ossec-lua ${DIR}/bin/
 cp -pr external/lua/src/ossec-luac ${DIR}/bin/
-chown root:${GROUP} ${DIR}/bin/util.sh
 chmod +x ${DIR}/bin/util.sh
 
 # Copying active response modules
@@ -210,10 +193,8 @@ sh ./init/fw-check.sh execute > /dev/nul
 cp -pr ../active-response/*.sh ${DIR}/active-response/bin/
 cp -pr ../active-response/firewalls/*.sh ${DIR}/active-response/bin/
 chmod 755 ${DIR}/active-response/bin/*
-chown root:${GROUP} ${DIR}/active-response/bin/*
 
-chown root:${GROUP} ${DIR}/bin/*
-chmod 550 ${DIR}/bin/*
+chmod 750 ${DIR}/bin/*
 
 
 # Moving the config file
@@ -229,7 +210,6 @@ if [ $? = 0 ]; then
 else    
     cp -pr ../etc/ossec-agent.conf ${DIR}/etc/ossec.conf
 fi
-chown root:${GROUP} ${DIR}/etc/ossec.conf
 chmod 440 ${DIR}/etc/ossec.conf
 
 
