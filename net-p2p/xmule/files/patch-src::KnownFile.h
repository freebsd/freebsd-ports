--- src/KnownFile.h.orig	Tue May 20 21:16:04 2003
+++ src/KnownFile.h	Tue May 20 21:23:46 2003
@@ -203,9 +203,6 @@
   (a) = MD4_ROTATE_LEFT((a), (s)); \
 }
 
-static void MD4Transform(uint32 Hash[4], uint32 x[16]);
-
-
 #if 0
 // old implementation
 class CFileStatistic{
