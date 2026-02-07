--- utils/cups-browsed.c.orig	2015-12-09 01:09:45 UTC
+++ utils/cups-browsed.c
@@ -23,17 +23,17 @@
 
 #include <ctype.h>
 #include <errno.h>
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
 #include <sys/socket.h>
 #endif /* __OpenBSD__ */
 #include <sys/types.h>
 #include <net/if.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
-#include <ifaddrs.h>
 #include <resolv.h>
 #include <stdio.h>
 #include <sys/stat.h>
+#include <ifaddrs.h>
 #include <stdlib.h>
 #include <time.h>
 #include <signal.h>
