--- src/ipacctd.c.orig	2022-08-30 21:59:34 UTC
+++ src/ipacctd.c
@@ -232,7 +232,11 @@
 	
 	ds.sin_family = AF_INET;
 
+#ifdef PF_DIVERT
+	if ((spkt = socket(PF_DIVERT, SOCK_RAW, 0)) == -1)
+#else
 	if ((spkt = socket(PF_INET, SOCK_RAW, IPPROTO_DIVERT)) == -1)
+#endif
 		err(1, "socket(IP_DIVERT)");
 	
 	if ((bind(spkt, (struct sockaddr *)&ds, sizeof(ds))) == -1)
