--- build/linux/python_arch.sh.orig	2011-06-08 21:00:57.020677627 +0300
+++ build/linux/python_arch.sh	2011-06-08 21:01:35.203676025 +0300
@@ -10,12 +10,7 @@
 #  python_arch.sh /path/to/sysroot/usr/lib/libpython2.4.so.1.0
 #
 
-python=$(readlink -f "$1")
-if [ ! -r "$python" ]; then
-  echo unknown
-  exit 0
-fi
-file_out=$(file "$python")
+file_out=$(file "$1")
 if [ $? -ne 0 ]; then
   echo unknown
   exit 0
