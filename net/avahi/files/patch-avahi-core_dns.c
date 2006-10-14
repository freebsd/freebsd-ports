--- avahi-core/dns.c.orig	Thu Oct 12 12:43:19 2006
+++ avahi-core/dns.c	Thu Oct 12 12:43:31 2006
@@ -28,6 +28,7 @@
 #include <stdio.h>
 #include <assert.h>
 
+#include <sys/types.h>
 #include <netinet/in.h>
 
 #include <avahi-common/defs.h>
