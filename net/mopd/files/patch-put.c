--- common/put.c.orig	Fri Aug 16 15:43:15 1996
+++ common/put.c	Sun Mar  5 09:32:05 2000
@@ -35,6 +35,9 @@
 #include <sys/types.h>
 #include <time.h>
 #include "common/mopdef.h"
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#endif
 
 void
 mopPutChar(pkt, index, value)
@@ -137,10 +140,7 @@
 		mopPutChar (pkt, index, 0x00);
 		mopPutChar (pkt, index, 0x2b);
 	}
-#if !defined(__FreeBSD__)
-	mopPutChar(pkt, index, (proto / 256));
-	mopPutChar(pkt, index, (proto % 256));
-#else
+#if defined(__FreeBSD__) && __FreeBSD_version < 220000
 	if (trans == TRANS_8023) {
 		mopPutChar(pkt, index, (proto / 256));
 		mopPutChar(pkt, index, (proto % 256));
@@ -148,6 +148,9 @@
 		mopPutChar(pkt, index, (proto % 256));
 		mopPutChar(pkt, index, (proto / 256));
 	}
+#else
+	mopPutChar(pkt, index, (proto / 256));
+	mopPutChar(pkt, index, (proto % 256));
 #endif
 	if (trans == TRANS_ETHER)
 		mopPutShort(pkt, index, 0);
@@ -170,12 +173,12 @@
 		break;
 	case TRANS_8023:
 		index = 12;
-#if !defined(__FreeBSD__)
-		mopPutChar(pkt, &index, ((len - 14) / 256));
+#if defined(__FreeBSD__) && __FreeBSD_version < 220000
 		mopPutChar(pkt, &index, ((len - 14) % 256));
+		mopPutChar(pkt, &index, ((len - 14) / 256));
 #else
-		mopPutChar(pkt, &index, ((len - 14) % 256));
 		mopPutChar(pkt, &index, ((len - 14) / 256));
+		mopPutChar(pkt, &index, ((len - 14) % 256));
 #endif
 		break;
 	}
