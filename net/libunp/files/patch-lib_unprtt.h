--- lib/unprtt.h.orig	1997-09-02 17:39:54 UTC
+++ lib/unprtt.h
@@ -1,7 +1,7 @@
 #ifndef	__unp_rtt_h
 #define	__unp_rtt_h
 
-#include	"unp.h"
+#include	<unp.h>
 
 struct rtt_info {
   float		rtt_rtt;	/* most recent measured RTT, seconds */
