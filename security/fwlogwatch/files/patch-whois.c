--- whois.c.orig	2016-02-19 06:35:50.592222000 -0800
+++ whois.c	2016-04-21 19:33:49.670304000 -0700
@@ -14,7 +14,9 @@
 #include <strings.h>
 #endif
 
+#define _KERNEL
 #include <netinet/in.h>
+#undef _KERNEL
 #include <arpa/inet.h>
 #include "main.h"
 #include "utils.h"
