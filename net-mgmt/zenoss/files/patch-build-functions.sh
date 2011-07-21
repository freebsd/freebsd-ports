$FreeBSD$

--- build-functions.sh.orig	2011-02-08 08:06:51.000000000 -0800
+++ build-functions.sh	2011-04-19 21:07:40.000000000 -0700
@@ -62,7 +62,7 @@
     export DESTDIR=/
 
     if [ -z "$ZENHOME" ] ; then
-        export ZENHOME=/usr/local/zenoss
+        export ZENHOME=`cat zenhome`
     fi
 
     if [ -z "$ZOPEHOME" ] ; then
@@ -417,8 +417,16 @@
     set_vars
     set_make
 
-    # verify all the input and environment
-    run_checks
+    # build the external libs and download zenoss
+    compile
+}
+
+# sets up variables and configure
+init()
+{
+    # initialize environment variables
+    set_vars
+    set_make
 
     # configure environment variables
     set_mysql
@@ -426,15 +434,6 @@
     # check mysql login
     check_mysql_login
 
-    # purge the last backup
-    purge_backup
-
-    # kill off any running zenoss processes
-    kill_running
-
-    # build the external libs and download zenoss
-    compile
-
     # perform post-installation configuration
     configure
 }
