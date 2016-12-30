--- acinclude.m4.orig	2006-01-09 10:35:59 UTC
+++ acinclude.m4
@@ -445,6 +445,7 @@ md5_calc(0, 0, 0);
     AC_MSG_RESULT([no])
 
     AC_CHECK_HEADERS([md5.h])
+    AC_CHECK_LIB([md],[MD5Data])
     AC_CHECK_FUNCS([MD5Data])
   ])
 ])
