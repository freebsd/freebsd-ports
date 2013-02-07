--- icb/c_time.c.orig	2000-12-15 12:21:02.000000000 +0900
+++ icb/c_time.c	2012-10-25 18:28:19.000000000 +0900
@@ -4,7 +4,7 @@
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #endif
-#ifdef STRING_H
+#ifdef HAVE_STRING_H
 #include <string.h>
 #endif
 #ifdef HAVE_TIME_H
