--- common/container/pub/hxbuffer.h	Thu Jul  8 21:45:51 2004
+++ common/container/pub/hxbuffer.h	Thu Jul  6 08:44:51 2006
@@ -61,5 +61,5 @@
 #define PnBufferShort
 #ifdef PnBufferShort
-const int MaxPnbufShortDataLen = 15;
+static const int MaxPnbufShortDataLen = 23;
 #endif
 
