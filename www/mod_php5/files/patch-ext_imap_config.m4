--- ext/imap/config.m4.orig	Tue May 22 02:38:46 2001
+++ ext/imap/config.m4	Fri Nov 23 19:40:39 2001
@@ -53,7 +53,7 @@
     PHP_ADD_LIBRARY_DEFER(ssl)
 
     old_LIBS=$LIBS
-    LIBS="$LIBS -lc-client"
+    LIBS="$LIBS -lc-client4"
     if test $PHP_KERBEROS != "no"; then
       LIBS="$LIBS -lgssapi_krb5 -lkrb5 -lk5crypto -lcom_err"
     fi
