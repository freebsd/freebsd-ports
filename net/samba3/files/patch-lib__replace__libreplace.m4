--- ./lib/replace/libreplace.m4.orig	2008-09-05 16:58:51.000000000 +0200
+++ ./lib/replace/libreplace.m4	2008-09-05 16:59:05.000000000 +0200
@@ -332,7 +332,6 @@
 m4_include(strptime.m4)
 m4_include(win32.m4)
 m4_include(timegm.m4)
-m4_include(repdir.m4)
 
 AC_CHECK_FUNCS([syslog memset memcpy],,[AC_MSG_ERROR([Required function not found])])
 
