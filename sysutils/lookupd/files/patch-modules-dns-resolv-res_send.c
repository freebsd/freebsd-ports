--- modules/dns/resolv/res_send.c.orig	Fri Jul  2 15:31:44 2004
+++ modules/dns/resolv/res_send.c	Wed Aug 10 18:09:22 2005
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
 
