--- inst.sh.orig	Thu Dec  6 19:52:24 2001
+++ inst.sh	Thu Dec  6 19:53:23 2001
@@ -1,8 +1,8 @@
 
 # (Large) prefix inserted above by Make
 
-# BSD systems keep chown in /etc
-PATH="$PATH:/etc"
+# BSD systems keep chown in /usr/sbin
+PATH="$PATH:/usr/sbin"
 
 case "$1" in
 mkdir)
@@ -83,8 +83,8 @@
 if [ -s ErrorCheck ]
 then
 	cat ErrorCheck
-	echo "Hit return to continue"
-	read X
+#	echo "Hit return to continue"
+#	read X
 fi
 rm -f ErrorCheck
 
