--- ./utils/cups-browsed.c.orig	2014-07-25 12:01:46.000000000 -0400
+++ ./utils/cups-browsed.c	2014-08-02 12:41:15.000000000 -0400
@@ -23,16 +23,16 @@
 
 #include <ctype.h>
 #include <errno.h>
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
 #include <sys/socket.h>
 #endif /* __OpenBSD__ */
 #include <net/if.h>
 #include <netinet/in.h>
-#include <ifaddrs.h>
 #include <resolv.h>
 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <ifaddrs.h>
 #include <assert.h>
 #include <stdlib.h>
 #include <time.h>
