--- dao/CdrDriver.cc.orig	2009-09-12 16:21:25 UTC
+++ dao/CdrDriver.cc
@@ -495,7 +495,7 @@ unsigned char CdrDriver::syncPattern[12]
   0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0
 };
 
-char CdrDriver::REMOTE_MSG_SYNC_[4] = { 0xff, 0x00, 0xff, 0x00 };
+unsigned char CdrDriver::REMOTE_MSG_SYNC_[4] = { 0xff, 0x00, 0xff, 0x00 };
 
 
 /* Maps a string to the corresponding driver option value 
