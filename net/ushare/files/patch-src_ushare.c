--- src/ushare.c.orig	Sun Jul  1 18:57:22 2007
+++ src/ushare.c	Wed Oct  3 11:03:45 2007
@@ -386,7 +386,8 @@
   unsigned char *ptr;
 
 #if (defined(BSD) || defined(__FreeBSD__))
-  int mib[6], len;
+  int mib[6];
+  size_t len;
   struct if_msghdr *ifm;
   struct sockaddr_dl *sdl;
 #else /* Linux */
