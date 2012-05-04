--- third_party/chromium/src/build/linux/python_arch.sh.org	2012-03-31 16:29:02.968788000 +0900
+++ third_party/chromium/src/build/linux/python_arch.sh	2012-03-31 17:00:18.892838462 +0900
@@ -10,7 +10,15 @@
 #  python_arch.sh /path/to/sysroot/usr/lib/libpython2.4.so.1.0
 #
 
-python=$(readlink -f "$1")
+UNAME=`uname`
+
+# FreeBSD readlink lacks -f support before 9.0
+if [ "${UNAME}" = "FreeBSD" ]; then
+  python=$(greadlink -f "$1")
+else
+  python=$(readlink -f "$1")
+fi
+
 if [ ! -r "$python" ]; then
   echo unknown
   exit 0
