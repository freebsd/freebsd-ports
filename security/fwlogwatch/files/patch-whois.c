--- whois.c.orig	2016-02-19 06:35:50.592222000 -0800
+++ whois.c	2021-11-01 08:45:36.119198000 -0700
@@ -14,7 +14,13 @@
 #include <strings.h>
 #endif
 
+#define _KERNEL
+#include <sys/param.h>
+#if __FreeBSD_version > 1400038
+#include <stdbool.h>
+#endif
 #include <netinet/in.h>
+#undef _KERNEL
 #include <arpa/inet.h>
 #include "main.h"
 #include "utils.h"
