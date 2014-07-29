--- malsync/mal/client/unix/MAL31DBConfig.c.orig	2008-04-15 19:49:54.000000000 +0200
+++ malsync/mal/client/unix/MAL31DBConfig.c	2008-04-15 19:50:04.000000000 +0200
@@ -20,7 +20,7 @@
  */
 
 #include <MAL31DBConfig.h>
-#if defined(DARWIN) || defined(__OpenBSD__)
+#if defined(DARWIN) || defined(__OpenBSD__) || defined(__FreeBSD__)
 #include <stdlib.h>
 #else
 #include <malloc.h>
