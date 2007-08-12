--- config.m4	2006-03-15 03:10:23.000000000 +0100
+++ config.m4.oden	2007-08-07 17:00:07.000000000 +0200
@@ -31,12 +31,12 @@
 
   PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
   [
-    PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $SSH2_DIR/lib, SSH2_SHARED_LIBADD)
+    PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $SSH2_DIR/$PHP_LIBDIR, SSH2_SHARED_LIBADD)
     AC_DEFINE(HAVE_SSH2LIB,1,[Have libssh2])
   ],[
     AC_MSG_ERROR([libssh2 version >= 0.4 not found])
   ],[
-    -L$SSH2_DIR/lib -lm 
+    -L$SSH2_DIR/$PHP_LIBDIR -lm 
   ])
 
   PHP_CHECK_LIBRARY($LIBNAME,libssh2_channel_forward_listen_ex,
@@ -45,7 +45,7 @@
   ],[
     AC_MSG_WARN([libssh2 <= 0.4, remote forwarding not enabled])
   ],[
-    -L$SSH2_DIR/lib -lm 
+    -L$SSH2_DIR/$PHP_LIBDIR -lm 
   ])
 
   PHP_CHECK_LIBRARY($LIBNAME,libssh2_userauth_hostbased_fromfile_ex,
@@ -54,7 +54,7 @@
   ],[
     AC_MSG_WARN([libssh2 <= 0.6, hostbased authentication not enabled])
   ],[
-    -L$SSH2_DIR/lib -lm 
+    -L$SSH2_DIR/$PHP_LIBDIR -lm 
   ])
 
   PHP_CHECK_LIBRARY($LIBNAME,libssh2_poll,
@@ -63,7 +63,7 @@
   ],[
     AC_MSG_WARN([libssh2 <= 0.7, poll support not enabled])
   ],[
-    -L$SSH2_DIR/lib -lm 
+    -L$SSH2_DIR/$PHP_LIBDIR -lm 
   ])
 
   PHP_CHECK_LIBRARY($LIBNAME,libssh2_publickey_init,
@@ -72,7 +72,7 @@
   ],[
     AC_MSG_WARN([libssh2 <= 0.11, publickey subsystem support not enabled])
   ],[
-    -L$SSH2_DIR/lib -lm 
+    -L$SSH2_DIR/$PHP_LIBDIR -lm 
   ])
   
   PHP_SUBST(SSH2_SHARED_LIBADD)
