--- ncat/ncat_core.c.orig	2009-04-02 04:57:42.000000000 +0200
+++ ncat/ncat_core.c	2009-04-16 14:12:39.000000000 +0200
@@ -11,6 +11,7 @@
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #endif
+#include <sys/param.h>
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
@@ -96,13 +97,22 @@
   rc = Snprintf(portbuf, sizeof(portbuf), "%hu", port);
   assert(rc >= 0 && rc < sizeof(portbuf));
 
+#if (defined(__FreeBSD_version) && (__FreeBSD_version < 800075) \
+    && ((__FreeBSD_version > 800000) || (__FreeBSD_version < 702000)))
+  rc = getaddrinfo(hostname, "domain", &hints, &result);
+#else
   rc = getaddrinfo(hostname, portbuf, &hints, &result);
+#endif
   if (rc != 0 || result == NULL)
       return 0;
   assert(result->ai_addrlen > 0 && result->ai_addrlen <= (int) sizeof(struct sockaddr_storage));
   *sslen = result->ai_addrlen;
   memcpy(ss, result->ai_addr, *sslen);
   freeaddrinfo(result);
+#if (defined(__FreeBSD_version) && (__FreeBSD_version < 800075) \
+    && ((__FreeBSD_version > 800000) || (__FreeBSD_version < 702000)))
+  ((struct sockaddr_in *)ss)->sin_port = htons(port);
+#endif
   return 1;
 }
 
