--- bin/vmd.sh.orig	2010-12-08 21:07:16.000000000 -0500
+++ bin/vmd.sh	2010-12-08 21:15:46.000000000 -0500
@@ -256,6 +256,12 @@
     if [ `uname -m` = "i386" ]
     then
       ARCH=FREEBSD
+    elif [ `uname -m` = "amd64" ]
+    then
+      ARCH=FREEBSDAMD64
+    else
+      echo "Error: unsupported FreeBSD version $MACHVER"
+      exit 1
     fi
     VMD_WINTERM=xterm
     VMD_WINOPTS='-sb -sl 1000 -e'
