--- libbalsa/imap/imap-handle.c.orig	Mon Jul 26 01:56:32 2004
+++ libbalsa/imap/imap-handle.c	Mon Jul 26 02:08:48 2004
@@ -18,10 +18,13 @@
  */
 #include "config.h"
 
+#ifndef __FreeBSD__
 #define _POSIX_SOURCE 1
+#endif
 #define _BSD_SOURCE   1
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <netdb.h>
 #include <glib.h>
 #include <glib-object.h>
@@ -360,9 +363,17 @@
   for (cur = res; cur != NULL; cur = cur->ai_next) {
     fd = socket (cur->ai_family, cur->ai_socktype, cur->ai_protocol);
     if (fd >= 0) {
+#ifdef __FreeBSD__
+      int sa_size = ((struct sockaddr_in *)cur->ai_addr)->sin_len;
+#else
       int sa_size = sizeof (struct sockaddr_in);
+#endif
       if (cur->ai_addr->sa_family == AF_INET6)
+#ifdef __FreeBSD__
+	sa_size = ((struct sockaddr_in6 *)cur->ai_addr)->sin6_len;
+#else
         sa_size = sizeof (struct sockaddr_in6);
+#endif
       if ((rc=connect(fd, cur->ai_addr, sa_size)) == 0) {
 	break;
       } else {
