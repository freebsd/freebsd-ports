--- aclocal.m4.orig	2008-03-09 14:35:51.000000000 +0100
+++ aclocal.m4	2008-09-23 11:23:56.000000000 +0200
@@ -1276,7 +1276,7 @@
   ;;
 
 freebsd*)
-  objformat=`test -x /usr/bin/objformat && /usr/bin/objformat || echo aout`
+  objformat=elf
   version_type=freebsd-$objformat
   case $version_type in
     freebsd-elf*)
