--- ./lib/replace/libreplace.m4.orig	2009-01-19 10:40:09.000000000 +0000
+++ ./lib/replace/libreplace.m4	2009-01-20 15:50:59.000000000 +0000
@@ -332,7 +332,6 @@
 m4_include(strptime.m4)
 m4_include(win32.m4)
 m4_include(timegm.m4)
-m4_include(repdir.m4)
 
 AC_CHECK_FUNCS([syslog memset memcpy],,[AC_MSG_ERROR([Required function not found])])
 
