--- libltdl/aclocal.m4.orig	2008-02-02 18:16:08.000000000 +0100
+++ libltdl/aclocal.m4	2008-09-23 11:26:47.000000000 +0200
@@ -1276,7 +1276,7 @@
   ;;
 
 freebsd*)
-  objformat=`test -x /usr/bin/objformat && /usr/bin/objformat || echo aout`
+  objformat=elf
   version_type=freebsd-$objformat
   case $version_type in
     freebsd-elf*)
