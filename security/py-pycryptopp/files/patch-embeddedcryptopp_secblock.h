--- embeddedcryptopp/secblock.h.orig	2013-11-02 21:05:08.220199000 +0000
+++ embeddedcryptopp/secblock.h
@@ -8,7 +8,7 @@
 #include <assert.h>
 
 #if defined(CRYPTOPP_MEMALIGN_AVAILABLE) || defined(CRYPTOPP_MM_MALLOC_AVAILABLE) || defined(QNX)
-	#include <malloc.h>
+	#include <stdlib.h>
 #endif
 
 NAMESPACE_BEGIN(CryptoPP)
@@ -94,7 +94,7 @@ public:
 
 	pointer allocate(size_type n, const void * = NULL)
 	{
-		CheckSize(n);
+		this->CheckSize(n);
 		if (n == 0)
 			return NULL;
 
