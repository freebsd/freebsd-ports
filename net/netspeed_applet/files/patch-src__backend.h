--- src/backend.h.orig	Wed Dec  1 13:43:47 2004
+++ src/backend.h	Fri Apr 22 01:28:34 2005
@@ -20,18 +20,20 @@
 #ifndef _BACKEND_H
 #define _BACKEND_H
 
+#include "config.h"
 #include <stdlib.h>
 #include <stdio.h>
 #include <unistd.h>
 #include <string.h>
 #include <ctype.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <net/if.h>
 #include <sys/ioctl.h>
 #include <glib.h>
-#ifdef USE_GLIBTOP
+#ifdef USE_LIBGTOP
 #include <glibtop/netload.h>
 #endif
 
