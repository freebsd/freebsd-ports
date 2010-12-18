--- bin/vmd.csh.orig	2010-12-08 20:55:17.000000000 -0500
+++ bin/vmd.csh 2010-12-08 21:10:21.000000000 -0500
@@ -218,6 +218,11 @@
   # The standard options
   if (`uname -m` == "i386") then
     set ARCH=FREEBSD
+  else if (`uname -m` == "amd64") then
+    set ARCH=FREEBSDAMD64
+  else
+    echo "Error: unsupported FreeBSD version $MACHVER"
+    exit 1
   endif
   set VMD_WINTERM=xterm
   set VMD_WINOPTS='-sb -sl 1000 -e'
