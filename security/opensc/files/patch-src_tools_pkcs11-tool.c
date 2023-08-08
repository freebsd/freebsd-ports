--- src/tools/pkcs11-tool.c.orig	2023-03-20 10:54:36 UTC
+++ src/tools/pkcs11-tool.c
@@ -7301,7 +7301,6 @@ static int test_random(CK_SESSION_HANDLE session)
 	CK_BYTE buf1[100], buf2[100];
 	CK_BYTE seed1[100];
 	CK_RV rv;
-	int errors = 0;
 
 	printf("C_SeedRandom() and C_GenerateRandom():\n");
 
@@ -7344,7 +7343,7 @@ static int test_random(CK_SESSION_HANDLE session)
 
 	if (memcmp(buf1, buf2, 100) == 0) {
 		printf("  ERR: C_GenerateRandom returned twice the same value!!!\n");
-		errors++;
+		return 1;
 	}
 
 	printf("  seems to be OK\n");
