--- src/xitk/network.c.orig	Fri Jun 28 23:03:50 2002
+++ src/xitk/network.c	Sat Jun 29 00:55:00 2002
@@ -24,9 +24,6 @@
  */
 /* required for getsubopt(); the __sun test avoids compilation problems on */
 /* solaris */
-#ifndef __sun
-#define _XOPEN_SOURCE 500
-#endif
 /* required for strncasecmp() */
 #define _BSD_SOURCE 1
 /* required to enable POSIX variant of getpwuid_r on solaris */
