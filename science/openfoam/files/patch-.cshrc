--- .cshrc.orig	Mon Aug  1 18:41:43 2005
+++ .cshrc	Fri Dec 30 18:35:49 2005
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
@@ -202,7 +208,7 @@
     AddLib $MPICH_ARCH_PATH/lib
     AddPath $MPICH_ARCH_PATH/bin
 
-    setenv FOAM_MPI_LIBBIN=$FOAM_LIBBIN/mpich-$MPICH_VERSION
+    setenv FOAM_MPI_LIBBIN $FOAM_LIBBIN/mpich-$MPICH_VERSION
     AddLib $FOAM_MPI_LIBBIN
 
 else if ($WM_MPLIB == LAM) then
