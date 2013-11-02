--- embeddedcryptopp/secblock.h.orig	2013-11-02 21:05:08.220199000 +0000
+++ embeddedcryptopp/secblock.h
@@ -94,7 +94,7 @@ public:
 
 	pointer allocate(size_type n, const void * = NULL)
 	{
-		CheckSize(n);
+		this->CheckSize(n);
 		if (n == 0)
 			return NULL;
 
