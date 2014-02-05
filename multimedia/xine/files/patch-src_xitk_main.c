--- src/xitk/main.c.orig	2012-01-19 11:04:00.000000000 +0000
+++ src/xitk/main.c
@@ -21,7 +21,7 @@
  *
  */
 /* required for getsubopt(); the __sun test gives us strncasecmp() on solaris */
-#if !defined(__sun) && ! defined(__FreeBSD__)
+#if !defined(__sun) && ! defined(__FreeBSD__) && ! defined(__DragonFly__)
 #define _XOPEN_SOURCE 500
 #endif
 /* required for strncasecmp() */
