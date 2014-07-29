--- lib/unprtt.h.orig	Thu Sep 30 11:13:16 1999
+++ lib/unprtt.h	Thu Sep 30 11:13:37 1999
@@ -1,7 +1,7 @@
 #ifndef	__unp_rtt_h
 #define	__unp_rtt_h
 
-#include	"unp.h"
+#include	<unp.h>
 
 struct rtt_info {
   float		rtt_rtt;	/* most recent measured RTT, seconds */
