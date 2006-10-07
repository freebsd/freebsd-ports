--- modules/dns/resolv/res_send.c.orig	Tue Aug  1 18:10:57 2006
+++ modules/dns/resolv/res_send.c	Tue Aug  1 18:11:02 2006
@@ -201,7 +201,7 @@
 	if (_res.options & RES_DEBUG) {
 		if (getnameinfo(address, address->sa_len, abuf, sizeof(abuf),
 				pbuf, sizeof(pbuf),
-				NI_NUMERICHOST | NI_NUMERICSERV | NI_WITHSCOPEID) != 0) {
+				NI_NUMERICHOST | NI_NUMERICSERV ) != 0) {
 			strncpy(abuf, "?", sizeof(abuf));
 			strncpy(pbuf, "?", sizeof(pbuf));
 		}
@@ -475,7 +475,7 @@
 			}
 			Dprint((_res.options & RES_DEBUG) &&
 				getnameinfo(nsap, salen, abuf, sizeof(abuf),
-					NULL, 0, NI_NUMERICHOST | NI_WITHSCOPEID) == 0,
+					NULL, 0, NI_NUMERICHOST ) == 0,
 				(stdout, ";; Querying server (# %d) address = %s\n",
 					ns + 1, abuf));
 
