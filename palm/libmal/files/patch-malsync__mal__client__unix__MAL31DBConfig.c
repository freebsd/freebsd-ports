--- malsync/mal/client/unix/MAL31DBConfig.c.orig	2009-02-16 16:07:04 UTC
+++ malsync/mal/client/unix/MAL31DBConfig.c
@@ -20,7 +20,7 @@
  */
 
 #include <MAL31DBConfig.h>
-#if defined(DARWIN) || defined(__OpenBSD__)
+#if defined(DARWIN) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #include <stdlib.h>
 #else
 #include <malloc.h>
