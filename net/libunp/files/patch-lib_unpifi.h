--- lib/unpifi.h.orig	1997-07-13 20:44:52 UTC
+++ lib/unpifi.h
@@ -4,7 +4,7 @@
 #ifndef	__unp_ifi_h
 #define	__unp_ifi_h
 
-#include	"unp.h"
+#include	<unp.h>
 #include	<net/if.h>
 
 #define	IFI_NAME	16			/* same as IFNAMSIZ in <net/if.h> */
