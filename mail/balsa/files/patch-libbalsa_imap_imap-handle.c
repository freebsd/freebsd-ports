--- libbalsa/imap/imap-handle.c.orig	Sun Feb 20 13:54:21 2005
+++ libbalsa/imap/imap-handle.c	Sat Mar 19 14:40:45 2005
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
