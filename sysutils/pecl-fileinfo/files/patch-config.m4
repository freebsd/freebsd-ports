--- config.m4.orig	Wed Jul 21 11:20:04 2004
+++ config.m4	Wed Jul 21 11:20:13 2004
@@ -36,7 +36,7 @@
   ],[
     AC_MSG_ERROR([wrong magic lib version or lib not found])
   ],[
-    -L$FILEINFO_DIR/lib -lm -ldl
+    -L$FILEINFO_DIR/lib -lm -lz
   ])
 
   MAGIC_MIME_LOCATIONS="/usr/local/share/file/magic /usr/share/file/magic /etc/magic"
