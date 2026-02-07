--- src/esp.c.orig	2018-07-19 13:30:02 UTC
+++ src/esp.c
@@ -21,6 +21,7 @@
 #include <arpa/inet.h>     // for inet_ntop, inet_pton
 #include <err.h>           // for err
 #include <errno.h>         // for __errno_location, errno, ERANGE
+#include <sys/types.h>     // for u_char
 #include <net/ethernet.h>  // for ether_header
 #include <netinet/ip.h>    // for ip
 #include <stdio.h>         // for printf, fclose, fgets, fopen, FILE
