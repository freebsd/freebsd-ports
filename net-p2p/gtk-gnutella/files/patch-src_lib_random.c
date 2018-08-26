--- src/lib/random.c.orig	2017-10-22 16:12:12 UTC
+++ src/lib/random.c
@@ -1058,7 +1058,9 @@ random_entropy(void *unused)
 		break;
 	case RANDOM_ARC4:
 		RANDOM_STATS_INC(arc4_distributed);
+#ifdef arc4random_addrandom
 		arc4random_addrandom(entropy, (int) ELEN);
+#endif
 		break;
 	case RANDOM_CMWC:
 		RANDOM_STATS_INC(cmwc_distributed);
