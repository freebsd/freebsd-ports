--- lib/cfsetup.c.orig	2007-12-05 16:26:10.000000000 +0900
+++ lib/cfsetup.c	2009-02-23 12:10:53.000000000 +0900
@@ -3636,15 +3636,15 @@
 			    "invalid kmp type %s\n", rct2str(proto));
 			return -1;
 		}
-		if (!kmp || !kmp->peers_ipaddr)
-			return -1;
-		for (al = kmp->peers_ipaddr; al != 0; al = al->next) {
-			if (al->type != RCT_ADDR_INET)
-				continue;
-			if (rcs_cmpsa_wop(al->a.ipaddr, s) != 0)
-				continue;
-			src = n;
-			goto found;
+		if (kmp && kmp->peers_ipaddr) {
+			for (al = kmp->peers_ipaddr; al != 0; al = al->next) {
+				if (al->type != RCT_ADDR_INET)
+					continue;
+				if (rcs_cmpsa_wop(al->a.ipaddr, s) != 0)
+					continue;
+				src = n;
+				goto found;
+			}
 		}
 	}
   found:
