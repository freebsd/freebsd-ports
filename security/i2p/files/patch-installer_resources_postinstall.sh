--- installer/resources/postinstall.sh.orig	2020-02-24 17:37:40 UTC
+++ installer/resources/postinstall.sh
@@ -57,7 +57,7 @@ case $HOST_OS in
         else
             wrapperpath="./lib/wrapper/linux64"
             # the 32bit libwrapper.so will be needed if a 32 bit jvm is used
-            cp ./lib/wrapper/linux/libwrapper.so ./lib/libwrapper-linux-x86-32.so
+            cp ./lib/wrapper/freebsd/libwrapper.so ./lib/libwrapper-freebsd-x86-32.so
         fi
         cp ${wrapperpath}/libwrapper.so ./lib/
         ;;
