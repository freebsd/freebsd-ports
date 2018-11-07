--- os.h.orig	2004-10-12 19:55:58 UTC
+++ os.h
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
