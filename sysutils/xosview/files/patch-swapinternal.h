--- bsd/swapinternal.h.orig	Wed Feb 11 21:04:07 1998
+++ bsd/swapinternal.h	Tue Aug 21 10:51:00 2001
@@ -12,7 +12,7 @@
 BSDInitSwapInfo();
 
 void
-BSDGetSwapInfo(int* total, int* free);
+BSDGetSwapInfo(int64_t* total, int64_t* free);
 #endif
 
 void
-BSDGetSwapCtlInfo(int* total, int* free);
+BSDGetSwapCtlInfo(int64_t* total, int64_t* free);
