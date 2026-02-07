--- pkt.h.orig	2002-04-07 22:55:20 UTC
+++ pkt.h
@@ -9,10 +9,14 @@
 #ifndef PKT_H
 #define PKT_H
 
+#include <sys/queue.h>
 #include <sys/time.h>
 #include <dnet.h>
 #include <event.h>
-#include "queue.h"
+
+#ifndef TAILQ_END
+#define TAILQ_END(head)	NULL
+#endif
 
 #define PKT_BUF_LEN	(ETH_HDR_LEN + ETH_MTU)
 #define PKT_BUF_ALIGN	2
