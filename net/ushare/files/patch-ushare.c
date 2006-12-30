--- src/ushare.c.orig	Sun Nov 12 13:40:35 2006
+++ src/ushare.c	Sat Dec 23 02:11:43 2006
@@ -33,6 +33,11 @@
 #include <unistd.h>
 #include <errno.h>
 #include <getopt.h>
+#if defined(__FreeBSD__)
+#include <sys/socket.h>
+#include <sys/sysctl.h>
+#include <net/if_dl.h>
+#endif
 #include <net/if.h>
 #include <sys/ioctl.h>
 #include <sys/types.h>
@@ -346,6 +351,48 @@
 static char *
 create_udn (char *interface)
 {
+#if defined(__FreeBSD__)
+  int mib[6], len;
+  char *buf;
+  unsigned char *ptr;
+  struct if_msghdr *ifm;
+  struct sockaddr_dl *sdl;
+  
+  mib[0] = CTL_NET;
+  mib[1] = AF_ROUTE;
+  mib[2] = 0;
+  mib[3] = AF_LINK;
+  mib[4] = NET_RT_IFLIST;
+  if((mib[5] = if_nametoindex(interface)) == 0) {
+    perror("if_nametoindex error");
+    exit(2);
+  }
+
+  if(sysctl(mib, 6, NULL, &len, NULL, 0) < 0) {
+    perror("sysctl 1 error");
+    exit(3);
+  }
+
+  if((buf = malloc(len)) == NULL) {
+    perror("malloc error");
+    exit(4);
+  }
+
+  if(sysctl(mib, 6, buf, &len, NULL, 0) < 0) {
+    perror("sysctl 2 error");
+    exit(5);
+  }
+
+  ifm = (struct if_msghdr *)buf;
+  sdl = (struct sockaddr_dl *)(ifm + 1);
+  ptr = (unsigned char *)LLADDR(sdl);
+
+  snprintf(buf, 64, "%02X%02X%02X%02X%02X%02X",
+    (ptr[0] & 0377), (ptr[1] & 0377), (ptr[2] & 0377),
+    (ptr[3] & 0377), (ptr[4] & 0377), (ptr[5] & 0377));
+
+  return buf;
+#else
   int sock;
   struct ifreq ifr;
   char *buf;
@@ -382,6 +429,7 @@
   close (sock);
 
   return buf;
+#endif
 }
 
 static char *
