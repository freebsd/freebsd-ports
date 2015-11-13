--- utils/cups-browsed.c.orig	2015-10-27 15:04:51 UTC
+++ utils/cups-browsed.c
@@ -23,16 +23,16 @@
 
 #include <ctype.h>
 #include <errno.h>
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
 #include <sys/socket.h>
 #endif /* __OpenBSD__ */
 #include <sys/types.h>
 #include <net/if.h>
 #include <netinet/in.h>
-#include <ifaddrs.h>
 #include <resolv.h>
 #include <stdio.h>
 #include <sys/stat.h>
+#include <ifaddrs.h>
 #include <stdlib.h>
 #include <time.h>
 #include <signal.h>
