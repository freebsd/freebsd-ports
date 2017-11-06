--- dao/CdrDriver.h.orig	2009-02-21 10:27:31 UTC
+++ dao/CdrDriver.h
@@ -440,7 +440,7 @@ protected:
   bool fullBurn_;
 
   static unsigned char syncPattern[12];
-  static char REMOTE_MSG_SYNC_[4];
+  static unsigned char REMOTE_MSG_SYNC_[4];
 
   static int speed2Mult(int);
   static int mult2Speed(int);
