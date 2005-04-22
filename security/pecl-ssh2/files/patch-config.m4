--- config.m4.orig	Thu Apr  7 11:18:20 2005
+++ config.m4	Thu Apr  7 11:19:10 2005
@@ -36,7 +36,7 @@
   ],[
     AC_MSG_ERROR([libssh2 version >= 0.4 not found])
   ],[
-    -L$SSH2_DIR/lib -lm -ldl
+    -L$SSH2_DIR/lib -lm
   ])
 
   PHP_CHECK_LIBRARY($LIBNAME,libssh2_channel_forward_listen_ex,
