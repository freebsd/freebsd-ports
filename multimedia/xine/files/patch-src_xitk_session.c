--- src/xitk/session.c.orig	2010-03-11 09:40:12.000000000 +0000
+++ src/xitk/session.c
@@ -21,7 +21,7 @@
 /* Largely inspired of xmms control socket stuff */
 
 /* required for getsubopt(); the __sun test gives us strncasecmp() on solaris */
-#if ! defined (__sun) && ! defined (__OpenBSD__) && ! defined (__FreeBSD__)
+#if ! defined (__sun) && ! defined (__OpenBSD__) && ! defined (__FreeBSD__) && !defined(__DragonFly__)
 #define _XOPEN_SOURCE 500
 #endif
 
