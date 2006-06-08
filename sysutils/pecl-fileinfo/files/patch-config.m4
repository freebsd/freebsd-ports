--- config.m4.orig	Thu Jun  8 15:20:41 2006
+++ config.m4	Thu Jun  8 15:52:29 2006
@@ -47,7 +47,7 @@
     -L$FILEINFO_DIR/lib
   ])
 
-  MAGIC_MIME_LOCATIONS="/usr/local/share/file/magic /usr/share/file/magic /usr/share/misc/file/magic /etc/magic /usr/share/misc"
+  MAGIC_MIME_LOCATIONS="/usr/local/share/file/magic /usr/share/misc/magic"
   for i in $MAGIC_MIME_LOCATIONS; do
     if test -f $i; then
        PHP_DEFAULT_MAGIC_FILE=$i
