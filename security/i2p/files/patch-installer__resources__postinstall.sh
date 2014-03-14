--- installer/resources/postinstall.sh.orig	2014-02-14 00:08:38.000000000 -0200
+++ installer/resources/postinstall.sh	2014-02-14 00:08:49.000000000 -0200
@@ -72,7 +72,7 @@
             wrapperpath="./lib/wrapper/freebsd64"
             cp ${wrapperpath}/libwrapper.so ./lib/
             # the 32bit libwrapper.so will be needed if a 32 bit jvm is used
-            cp ./lib/freebsd/libwrapper.so ./lib/libwrapper-freebsd-x86-32.so
+            cp ./lib/wrapper/freebsd/libwrapper.so ./lib/libwrapper-freebsd-x86-32.so
         fi
         ;;
     osx )
