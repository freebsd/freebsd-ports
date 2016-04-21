--- src/InstallServer.sh.orig	2015-10-12 21:21:06 UTC
+++ src/InstallServer.sh
@@ -44,13 +44,13 @@ fi
 
 # Creating groups/users
 if [ "$UNAME" = "FreeBSD" -o "$UNAME" = "DragonFly" ]; then
-    grep "^${USER_REM}" /etc/passwd > /dev/null 2>&1
-    if [ ! $? = 0 ]; then
-    /usr/sbin/pw groupadd ${GROUP}
-	/usr/sbin/pw useradd ${USER} -d ${DIR} -s /sbin/nologin -g ${GROUP}
-	/usr/sbin/pw useradd ${USER_MAIL} -d ${DIR} -s /sbin/nologin -g ${GROUP}
-	/usr/sbin/pw useradd ${USER_REM} -d ${DIR} -s /sbin/nologin -g ${GROUP}
-    fi
+#    grep "^${USER_REM}" /etc/passwd > /dev/null 2>&1
+#    if [ ! $? = 0 ]; then
+#    /usr/sbin/pw groupadd ${GROUP}
+#	/usr/sbin/pw useradd ${USER} -d ${DIR} -s /sbin/nologin -g ${GROUP}
+#	/usr/sbin/pw useradd ${USER_MAIL} -d ${DIR} -s /sbin/nologin -g ${GROUP}
+#	/usr/sbin/pw useradd ${USER_REM} -d ${DIR} -s /sbin/nologin -g ${GROUP}
+#    fi
 
 elif [ "$UNAME" = "SunOS" ]; then
     grep "^${USER_REM}" /etc/passwd > /dev/null 2>&1
@@ -121,66 +121,49 @@ for i in ${subdirs}; do
 done
 
 # Default for all directories
-chmod 550 ${DIR}
-chmod 550 ${DIR}/*
-chown root:${GROUP} ${DIR}
-chown root:${GROUP} ${DIR}/*
+chmod 750 ${DIR}
+chmod 750 ${DIR}/*
 
 # AnalysisD needs to write to alerts: log, mail and cmds
-chown -R ${USER}:${GROUP} ${DIR}/queue/alerts
 chmod -R 770 ${DIR}/queue/alerts
 
 # To the ossec queue (default for analysisd to read)
-chown -R ${USER}:${GROUP} ${DIR}/queue/ossec
 chmod -R 770 ${DIR}/queue/ossec
 
 # To the ossec fts queue
-chown -R ${USER}:${GROUP} ${DIR}/queue/fts
 chmod -R 750 ${DIR}/queue/fts
 chmod 750 ${DIR}/queue/fts/* > /dev/null 2>&1
 
 # To the ossec syscheck/rootcheck queue
-chown -R ${USER}:${GROUP} ${DIR}/queue/syscheck
 chmod -R 750 ${DIR}/queue/syscheck
 chmod 740 ${DIR}/queue/syscheck/* > /dev/null 2>&1
 
-chown -R ${USER}:${GROUP} ${DIR}/queue/rootcheck
 chmod -R 750 ${DIR}/queue/rootcheck
 chmod 740 ${DIR}/queue/rootcheck/* > /dev/null 2>&1
 
-chown ${USER}:${GROUP} ${DIR}/queue/diff
-chown ${USER}:${GROUP} ${DIR}/queue/diff/* > /dev/null 2>&1
 chmod 750 ${DIR}/queue/diff
 chmod 740 ${DIR}/queue/diff/* > /dev/null 2>&1
 
-chown -R ${USER_REM}:${GROUP} ${DIR}/queue/agent-info
 chmod -R 750 ${DIR}/queue/agent-info
 chmod 740 ${DIR}/queue/agent-info/* > /dev/null 2>&1
-chown -R ${USER_REM}:${GROUP} ${DIR}/queue/rids
 chmod -R 750 ${DIR}/queue/rids
 chmod 740 ${DIR}/queue/rids/* > /dev/null 2>&1
 
-chown -R ${USER}:${GROUP} ${DIR}/queue/agentless
 chmod -R 750 ${DIR}/queue/agentless
 chmod 740 ${DIR}/queue/agentless/* > /dev/null 2>&1
 
-chown -R root:${GROUP} ${DIR}/tmp
-chmod 1550 ${DIR}/tmp
+chmod 1750 ${DIR}/tmp
 
 
 # For the stats directory
-chown -R ${USER}:${GROUP} ${DIR}/stats
 chmod -R 750 ${DIR}/stats
 
 # For the logging user
-chown -R ${USER}:${GROUP} ${DIR}/logs
 chmod -R 750 ${DIR}/logs
 touch ${DIR}/logs/ossec.log
-chown ${USER}:${GROUP} ${DIR}/logs/ossec.log
 chmod 660 ${DIR}/logs/ossec.log
 
 touch ${DIR}/logs/active-responses.log
-chown ${USER}:${GROUP} ${DIR}/logs/active-responses.log
 chmod 660 ${DIR}/logs/active-responses.log
 
 # For the rules directory
@@ -198,7 +181,7 @@ if [ $? = 0 ]; then
     fi    
 fi
     
-cp -pr ../etc/rules/* ${DIR}/rules/
+cp -pr ../etc/rules/*.xml ${DIR}/rules/
 find ${DIR}/rules/ -type f -exec chmod 440 {} \;
 
 # If the local_rules is saved, moved it back
@@ -207,37 +190,33 @@ if [ $? = 0 ]; then
     mv ${DIR}/rules/saved_local_rules.xml.$$ ${DIR}/rules/local_rules.xml
 fi    
 
-chown -R root:${GROUP} ${DIR}/rules
-chmod -R 550 ${DIR}/rules
+chmod -R 750 ${DIR}/rules
 
 
 # For the etc dir
-chmod 550 ${DIR}/etc
-chown -R root:${GROUP} ${DIR}/etc
+chmod 750 ${DIR}/etc
 ls /etc/localtime > /dev/null 2>&1
 if [ $? = 0 ]; then
     cp -pL /etc/localtime ${DIR}/etc/;
     chmod 440 ${DIR}/etc/localtime
-    chown root:${GROUP} ${DIR}/etc/localtime 
 fi
 
 # Solaris Needs some extra files
 if [ "$UNAME" = "SunOS" ]; then
     mkdir -p ${DIR}/usr/share/lib/zoneinfo/
-    chmod -R 550 ${DIR}/usr/
+    chmod -R 750 ${DIR}/usr/
     cp -pr /usr/share/lib/zoneinfo/* ${DIR}/usr/share/lib/zoneinfo/
 fi
 
 ls /etc/TIMEZONE > /dev/null 2>&1
 if [ $? = 0 ]; then
     cp -p /etc/TIMEZONE ${DIR}/etc/;
-    chmod 550 ${DIR}/etc/TIMEZONE
+    chmod 750 ${DIR}/etc/TIMEZONE
 fi
                         
 
 # For the /var/run
 chmod 770 ${DIR}/var/run
-chown root:${GROUP} ${DIR}/var/run
 
 # Moving the binary files
 cp -pr addagent/manage_agents agentlessd/ossec-agentlessd \
@@ -260,7 +239,6 @@ cp -pr util/rootcheck_control ${DIR}/bin
 cp -pr external/lua/src/ossec-lua ${DIR}/bin/
 cp -pr external/lua/src/ossec-luac ${DIR}/bin/
 cp -pr ../contrib/util.sh ${DIR}/bin/
-chown root:${GROUP} ${DIR}/bin/util.sh
 chmod +x ${DIR}/bin/util.sh
 
 # Local install chosen
@@ -290,23 +268,15 @@ fi
   
 cp -pr ../etc/internal_options.conf ${DIR}/etc/
 cp -pr rootcheck/db/*.txt ${DIR}/etc/shared/
-chown root:${GROUP} ${DIR}/etc/decoder.xml
-chown root:${GROUP} ${DIR}/etc/local_decoder.xml >/dev/null 2>&1
-chown root:${GROUP} ${DIR}/etc/internal_options.conf
-chown root:${GROUP} ${DIR}/etc/local_internal_options.conf >/dev/null 2>&1
-chown root:${GROUP} ${DIR}/etc/client.keys >/dev/null 2>&1
-chown root:${GROUP} ${DIR}/etc/shared/*
-chown root:${GROUP} ${DIR}/agentless/*
-chown ${USER}:${GROUP} ${DIR}/.ssh
 chmod 440 ${DIR}/etc/decoder.xml
 chmod 440 ${DIR}/etc/local_decoder.xml >/dev/null 2>&1
 chmod 440 ${DIR}/etc/internal_options.conf
 chmod 440 ${DIR}/etc/local_internal_options.conf >/dev/null 2>&1
 chmod 440 ${DIR}/etc/client.keys >/dev/null 2>&1
-chmod 550 ${DIR}/etc
+chmod 750 ${DIR}/etc
 chmod 770 ${DIR}/etc/shared
 chmod 440 ${DIR}/etc/shared/*
-chmod 550 ${DIR}/agentless/*
+chmod 750 ${DIR}/agentless/*
 rm ${DIR}/etc/shared/merged.mg >/dev/null 2>&1
 chmod 700 ${DIR}/.ssh
 
@@ -316,11 +286,9 @@ sh ./init/fw-check.sh execute > /dev/nul
 cp -p ../active-response/*.sh ${DIR}/active-response/bin/
 cp -p ../active-response/firewalls/*.sh ${DIR}/active-response/bin/
 
-chmod 550 ${DIR}/active-response/bin/*
-chown root:${GROUP} ${DIR}/active-response/bin/*
+chmod 750 ${DIR}/active-response/bin/*
 
-chown root:${GROUP} ${DIR}/bin/*
-chmod 550 ${DIR}/bin/*
+chmod 750 ${DIR}/bin/*
 
 
 # Moving the config file
@@ -331,12 +299,11 @@ fi
 
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
+chmod 640 ${DIR}/etc/ossec.conf.sample
 
 
 
