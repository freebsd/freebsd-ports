--- bin/dhgen/dhgen.cc.orig	2013-06-16 10:57:08.000000000 +0900
+++ bin/dhgen/dhgen.cc	2013-06-16 10:59:01.000000000 +0900
@@ -233,21 +233,21 @@
 	}
 
 #ifdef TAHI
-	printf("log:DHGen_Results                   (length:%i)\n",
+	printf("log:DHGen_Results                   (length:%zu)\n",
 		xflag?
-			BN_num_bytes(pDH->pub_key) +
-				BN_num_bytes(pDH->priv_key):
+			(size_t)(BN_num_bytes(pDH->pub_key) +
+				BN_num_bytes(pDH->priv_key)):
 			strlen(pPubKey) + strlen(pPrivKey));
 #else	// TAHI
-	printf("log:DHGen_Results                   (length:%i)\n", strlen(pPubKey) + strlen(pPrivKey));
+	printf("log:DHGen_Results                   (length:%zu)\n", strlen(pPubKey) + strlen(pPrivKey));
 #endif	// TAHI
 #ifdef TAHI
-	printf("log:| Public_Key                      (length:%i)\n",
+	printf("log:| Public_Key                      (length:%zu)\n",
 		xflag?
-			BN_num_bytes(pDH->pub_key):
+			(size_t)BN_num_bytes(pDH->pub_key):
 			strlen(pPubKey));
 #else	// TAHI
-	printf("log:| Public_Key                      (length:%i)\n", strlen(pPubKey));
+	printf("log:| Public_Key                      (length:%zu)\n", strlen(pPubKey));
 #endif	// TAHI
 #ifdef TAHI
 	xflag? xPrintResult(pPubKey): PrintResult(pPubKey);
@@ -255,12 +255,12 @@
 	PrintResult(pPubKey);
 #endif	// TAHI
 #ifdef TAHI
-	printf("log:| Private_Key                     (length:%i)\n",
+	printf("log:| Private_Key                     (length:%zu)\n",
 		xflag?
-			BN_num_bytes(pDH->priv_key):
+			(size_t)BN_num_bytes(pDH->priv_key):
 			strlen(pPrivKey));
 #else	// TAHI
-	printf("log:| Private_Key                     (length:%i)\n", strlen(pPrivKey));
+	printf("log:| Private_Key                     (length:%zu)\n", strlen(pPrivKey));
 #endif	// TAHI
 #ifdef TAHI
 	xflag? xPrintResult(pPrivKey): PrintResult(pPrivKey);
