--- build/linux/python_arch.sh.orig	2011-09-27 21:20:46.000000000 -0400
+++ build/linux/python_arch.sh	2011-10-11 19:20:09.472740606 -0400
@@ -10,7 +10,7 @@
 #  python_arch.sh /path/to/sysroot/usr/lib/libpython2.4.so.1.0
 #
 
-python=$(readlink -f "$1")
+python=$(greadlink -f "$1")
 if [ ! -r "$python" ]; then
   echo unknown
   exit 0;
