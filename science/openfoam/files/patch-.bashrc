--- .bashrc.orig	Mon Aug  1 18:41:21 2005
+++ .bashrc	Fri Dec 30 18:36:45 2005
@@ -135,6 +135,12 @@
         export JAVA_HOME=/usr/java/j2sdk1.4.2
     fi
 
+# FreeBSD workstation
+# ~~~~~~~~~~~~~~~~~~~
+elif [ "$machineTest" = "FreeBSD" ]; then
+
+    export JAVA_HOME=%%JAVA_HOME%%
+
 # SUN workstation 
 # ~~~~~~~~~~~~~~~
 elif [ "$machineTest" = "SunOS" ]; then
