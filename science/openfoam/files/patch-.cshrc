--- .cshrc.orig	Fri Mar 24 16:46:13 2006
+++ .cshrc	Thu Mar 30 22:02:51 2006
@@ -130,6 +130,12 @@
         setenv JAVA_HOME /usr/java/j2sdk1.4.2
     endif
 
+# FreeBSD workstation
+# ~~~~~~~~~~~~~~~~~~~
+else if ($machineTest == FreeBSD) then
+
+    setenv JAVA_HOME %%JAVA_HOME%%
+
 # SUN workstation 
 # ~~~~~~~~~~~~~~~
 else if ($machineTest == SunOS) then
