--- src/openvpn-cr.c.orig	2018-07-26 20:17:21 UTC
+++ src/openvpn-cr.c
@@ -29,7 +29,7 @@ int extract_openvpn_cr(const char *response, openvpn_r
 	tokenIndexes[0] = response;
 	int tokenCnt = 1;
 	const char *p;
-	for (p = response; *p; ++p) {
+	for (p = response; *p && tokenCnt < 15; ++p) {
 		if (*p == ':')
 			tokenIndexes[tokenCnt++] = p + 1;
 	}
