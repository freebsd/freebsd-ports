--- svdrp.c.orig	2026-06-01 16:59:58 UTC
+++ svdrp.c
@@ -73,7 +73,7 @@ public:
 
 cIpAddress::cIpAddress(void)
 {
-  Set(INADDR_ANY, 0);
+  Set(NULL, 0);
 }
 
 cIpAddress::cIpAddress(const char *Address, int Port)
