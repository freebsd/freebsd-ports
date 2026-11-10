--- utils/cups-browsed.c.orig	2015-12-09 01:09:45 UTC
+++ utils/cups-browsed.c
@@ -23,7 +23,7 @@
 
 #include <ctype.h>
 #include <errno.h>
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
 #include <sys/socket.h>
 #endif /* __OpenBSD__ */
 #include <sys/types.h>
