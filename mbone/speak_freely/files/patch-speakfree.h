--- speakfree.h
+++ speakfree.h
@@ -13,10 +13,6 @@
 #define BSD_like
 #endif
 
-#ifdef __FreeBSD__
-#define BSD_like
-#endif
-
 #ifdef sgi
 #define _BSD_SIGNALS
 #endif
