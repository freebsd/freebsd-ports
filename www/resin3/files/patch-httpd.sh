--- bin/httpd.sh.orig	Tue Sep 23 00:54:37 2003
+++ bin/httpd.sh	Mon Sep 29 10:33:13 2003
@@ -37,11 +37,8 @@
 #
 # You can predefine JAVA_HOME and RESIN_HOME
 #
-# JAVA_HOME=/usr/java
-# export JAVA_HOME
-#
-# RESIN_HOME=/usr/local/resin
-# export RESIN_HOME
+export JAVA_HOME=%%JAVA_HOME%%
+export RESIN_HOME=%%PREFIX%%/%%PKGNAMEPREFIX%%%%PORTNAME%%
 #
 # Extra arguments to Java.  If you're passing arguments to the JVM, you'll
 # need to use -Jxxx.  For example, args="-J-ms48m".  You can modify
@@ -68,15 +65,13 @@
 #
 # ulimit -s 2048
 #
-# trace script and simlinks to find thw wrapper
-#
-script=`/bin/ls -l $0 | awk '{ print $NF; }'`
-
-while test -h "$script"
-do
-  script=`/bin/ls -l $script | awk '{ print $NF; }'`
-done
-
-bin=`dirname $script`
 
-exec $perl $bin/wrapper.pl -chdir -name "$name" -class "$class" $args $*
+su -f -m www -c \
+"exec $perl %%PREFIX%%/sbin/resinctl \
+-pid /var/run/resin.pid \
+-conf %%PREFIX%%/etc/resin.xml \
+-chdir -name "$name" \
+-class "$class" \
+$args $*" \
+> /dev/null \
+&& echo -n '%%PKGNAMEPREFIX%%%%PORTNAME%% '
