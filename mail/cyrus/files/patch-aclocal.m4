--- aclocal.m4.orig	Tue Oct 28 05:08:17 2003
+++ aclocal.m4	Tue Oct 28 05:08:23 2003
@@ -84,7 +84,7 @@
     # try the user-specified path --- too lazy to test for it right now
     LIB_SASL="-L$sasldir/lib -lsasl"
     AC_SUBST(LIB_SASL)
-    SASLFLAGS="-I$sasldir/include"
+    SASLFLAGS="-I$sasldir/include/sasl1"
     AC_SUBST(SASLFLAGS)    
   fi
 ])
