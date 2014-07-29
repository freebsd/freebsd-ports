--- tcpip.c.orig	Tue Sep 22 13:35:43 1998
+++ tcpip.c	Sat Oct 24 11:46:58 1998
@@ -25,6 +25,12 @@
 #include <stdarg.h>
 #include <net/if.h>
 
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__bsdi__)
+#include <err.h>
+#include <errno.h>
+#include <sysexits.h>
+#endif
+
 #include "tcpip.h"
 
 /*-- LINUX routilng TABLES */
@@ -333,7 +339,64 @@
         }
     }
 
-#else /* !LINUX ---------------------------------------------- OTHER --*/
+/*------------------------------- FreeBSD / OpenBSD / NetBSD / BSDI --*/
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__bsdi__)
+/* 
+        FreeBSD Ref: /usr/share/examples/find_interface/ 
+*/
+        struct sockaddr_in local, remote;
+        int s, rv, namelen;
+
+        remote.sin_addr.s_addr = dest;
+        remote.sin_port = htons(60000);
+        remote.sin_family = AF_INET;
+        remote.sin_len = sizeof remote;
+
+        local.sin_addr.s_addr = htonl(INADDR_ANY);
+        local.sin_port = htons(60000);
+        local.sin_family = AF_INET;
+        local.sin_len = sizeof local;
+
+        s = socket(PF_INET, SOCK_DGRAM, 0);
+        if (s < 0)
+          err(EX_OSERR, "socket");
+
+        do 
+	  {
+            rv = bind(s, (struct sockaddr *)&local, sizeof local);
+            local.sin_port = htons(ntohs(local.sin_port) + 1);
+          } while(rv < 0 && errno == EADDRINUSE);
+
+        if (rv < 0)
+          err(EX_OSERR, "bind");
+
+        do
+	  {
+            rv = connect(s, (struct sockaddr *)&remote, sizeof remote);
+            remote.sin_port = htons(ntohs(remote.sin_port) + 1);
+          } while(rv < 0 && errno == EADDRINUSE);
+
+        if (rv < 0)
+          err(EX_OSERR, "bind");
+
+        do
+	  {
+            rv = connect(s, (struct sockaddr *)&remote, sizeof remote);
+            remote.sin_port = htons(ntohs(remote.sin_port) + 1);
+          } while(rv < 0 && errno == EADDRINUSE);
+
+        if (rv < 0)
+          err(EX_OSERR, "connect");
+
+        namelen = sizeof local;
+        rv = getsockname(s, (struct sockaddr *)&local, &namelen);
+
+        if (rv < 0)
+          err(EX_OSERR, "getsockname");
+
+	return local.sin_addr;
+
+#else /* !LINUX && !BSD ---------------------------------- OTHER --*/
   struct sockaddr_in sin; 
   char myname[80];
   
