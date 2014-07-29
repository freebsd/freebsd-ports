--- installer/resources/postinstall.sh.orig	2014-07-28 20:57:21.000000000 +0200
+++ installer/resources/postinstall.sh	2014-07-28 20:58:49.000000000 +0200
@@ -53,7 +53,7 @@
         else
             wrapperpath="./lib/wrapper/linux64"
             # the 32bit libwrapper.so will be needed if a 32 bit jvm is used
-            cp ./lib/wrapper/linux/libwrapper.so ./lib/libwrapper-linux-x86-32.so
+            cp ./lib/wrapper/freebsd/libwrapper.so ./lib/libwrapper-freebsd-x86-32.so
         fi
         cp ${wrapperpath}/libwrapper.so ./lib/
         ;;
