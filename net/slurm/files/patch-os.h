--- os.h.orig	2009-09-25 02:57:02.000000000 +0200
+++ os.h	2009-09-25 03:06:20.000000000 +0200
@@ -92,10 +92,6 @@
 #include <net/if_media.h>
 #include <net/if_mib.h>
 #include <arpa/inet.h>
-#ifndef __DragonFly__
-#include <net/ppp_defs.h>
-#include <net/if_ppp.h>
-#endif
 #elif __NetBSD__            /* N E T B S D */
 #include <stdio.h>
 #include <sys/param.h>
