--- src/ndisc.c.orig	2026-10-04 09:31:16 UTC
+++ src/ndisc.c
@@ -511,7 +511,7 @@ parsepref64 (const uint8_t *opt)
 		return -1;
 
 	memcpy(&pref64, opt + 4, 12);
-	pref64.s6_addr32[3] = 0;
+	memset(&pref64.s6_addr[12], 0, 4);
 	if (inet_ntop (AF_INET6, &pref64, str, sizeof (str)) == NULL)
 		return -1;
 
