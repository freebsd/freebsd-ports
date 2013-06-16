--- bin/dhcomp/dhcomp.cc.orig	2013-06-16 10:59:39.000000000 +0900
+++ bin/dhcomp/dhcomp.cc	2013-06-16 11:00:26.000000000 +0900
@@ -315,14 +315,14 @@
 	memcpy(&pSharedKey[iSharedKeyLen - l], pSharedKeyStock, l);
 
 #ifdef TAHI
-	printf("log:DHComp_Results                  (length:%i)\n",
-		xflag? iSharedKeyLen: strlen(pSharedKey));
-	printf("log:| Shared_Key                      (length:%i)\n",
-		xflag? iSharedKeyLen: strlen(pSharedKey));
+	printf("log:DHComp_Results                  (length:%zu)\n",
+		xflag? (size_t)iSharedKeyLen: strlen(pSharedKey));
+	printf("log:| Shared_Key                      (length:%zu)\n",
+		xflag? (size_t)iSharedKeyLen: strlen(pSharedKey));
 	xflag? xPrintResult(pSharedKey): PrintResult(pSharedKey);
 #else	// TAHI
-	printf("log:DHComp_Results                  (length:%i)\n", strlen(pSharedKey));
-	printf("log:| Shared_Key                      (length:%i)\n", strlen(pSharedKey));
+	printf("log:DHComp_Results                  (length:%zu)\n", strlen(pSharedKey));
+	printf("log:| Shared_Key                      (length:%zu)\n", strlen(pSharedKey));
 	PrintResult(pSharedKey);
 #endif	// TAHI
 
