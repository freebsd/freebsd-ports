--- utils/cups-browsed.c.orig	2014-04-05 16:31:42.635763683 +0400
+++ utils/cups-browsed.c	2014-04-05 16:37:07.384740688 +0400
@@ -23,8 +23,7 @@
 
 #include <ctype.h>
 #include <errno.h>
-#include <ifaddrs.h>
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
 #include <sys/socket.h>
 #endif /* __OpenBSD__ */
 #include <net/if.h>
@@ -33,6 +32,7 @@
 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <ifaddrs.h>
 #include <assert.h>
 #include <stdlib.h>
 #include <time.h>
