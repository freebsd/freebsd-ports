--- snmp_ntp/snmp_ntp.c.orig	Mon May 23 06:03:48 2005
+++ snmp_ntp/snmp_ntp.c	Mon Sep 26 12:50:42 2005
@@ -40,7 +40,11 @@
 #include <ctype.h>
 #include <errno.h>
 #include <netdb.h>
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
+#elif defined(HAVE_INTTYPES_H)
+#include <inttypes.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -360,6 +364,7 @@
 		free(rpkt);
 		return (-1);
 	}
+	return 0;
 }
 
 /*
@@ -720,7 +725,7 @@
 {
 	int r, n, error;
 	struct addrinfo hints, *res0;
-	struct sockaddr_in *sin;
+	struct sockaddr_in *sin_local;
 
 	r = sscanf(val, "%hhd.%hhd.%hhd.%hhd%n",
 	    &ip[0], &ip[1], &ip[2], &ip[3], &n);
@@ -743,11 +748,11 @@
 		return (-1);
 	}
 
-	sin = (struct sockaddr_in *)(void *)res0->ai_addr;
-	ip[3] = sin->sin_addr.s_addr >> 24;
-	ip[2] = sin->sin_addr.s_addr >> 16;
-	ip[1] = sin->sin_addr.s_addr >>  8;
-	ip[0] = sin->sin_addr.s_addr >>  0;
+	sin_local = (struct sockaddr_in *)(void *)res0->ai_addr;
+	ip[3] = sin_local->sin_addr.s_addr >> 24;
+	ip[2] = sin_local->sin_addr.s_addr >> 16;
+	ip[1] = sin_local->sin_addr.s_addr >>  8;
+	ip[0] = sin_local->sin_addr.s_addr >>  0;
 
 	freeaddrinfo(res0);
 	return (0);
