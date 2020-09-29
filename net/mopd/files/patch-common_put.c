--- common/put.c.orig	1996-08-16 22:43:15 UTC
+++ common/put.c
@@ -35,6 +35,9 @@ static char rcsid[] = "$Id: put.c,v 1.5 1996/08/16 22:
 #include <sys/types.h>
 #include <time.h>
 #include "common/mopdef.h"
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#endif
 
 void
 mopPutChar(pkt, index, value)
@@ -137,10 +140,7 @@ mopPutHeader(pkt, index, dst, src, proto, trans)
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
@@ -148,6 +148,9 @@ mopPutHeader(pkt, index, dst, src, proto, trans)
 		mopPutChar(pkt, index, (proto % 256));
 		mopPutChar(pkt, index, (proto / 256));
 	}
+#else
+	mopPutChar(pkt, index, (proto / 256));
+	mopPutChar(pkt, index, (proto % 256));
 #endif
 	if (trans == TRANS_ETHER)
 		mopPutShort(pkt, index, 0);
@@ -170,12 +173,12 @@ mopPutLength(pkt, trans, len)
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
