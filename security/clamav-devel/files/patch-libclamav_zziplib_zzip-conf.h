--- libclamav/zziplib/zzip-conf.h.orig	Mon Nov 24 17:52:56 2003
+++ libclamav/zziplib/zzip-conf.h	Mon Nov 24 17:53:05 2003
@@ -11,6 +11,8 @@
 #ifndef _ZZIP_CONF_H
 #define _ZZIP_CONF_H 1
 
+#include <sys/types.h>
+
 #if !defined ZZIP_OMIT_CONFIG_H
 # if defined _MSC_VER || defined __BORLANDC__ || defined __WATCOMC__
 # include <zzip-msvc.h>
