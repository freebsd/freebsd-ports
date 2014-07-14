--- ./src/InstallAgent.sh.orig	2014-07-13 15:25:05.161395378 -0600
+++ ./src/InstallAgent.sh	2014-07-13 15:25:35.972393742 -0600
@@ -37,11 +37,11 @@
 
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
