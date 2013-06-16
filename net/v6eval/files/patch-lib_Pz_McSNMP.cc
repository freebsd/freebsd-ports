--- lib/Pz/McSNMP.cc.orig	2013-06-16 10:35:43.000000000 +0900
+++ lib/Pz/McSNMP.cc	2013-06-16 10:36:50.000000000 +0900
@@ -563,7 +563,7 @@
 	COCTSTR s=string();
 	for(i=0;i<i9;i++)
 		printf("%02x",s[i]&0xff);
-	printf((tag!=0&&length()>16)?tag:"");
+	printf("%s", (tag!=0&&length()>16)?tag:"");
 	int a=(int)(s[0]&0xff);
 	sprintf(tmp, "%d.%d.",(int)(a/40), (int)(a%40));
 	/* ASN.1 decode */	
