--- trackdb/FormatOgg.cc.orig	2010-06-06 16:45:05.000000000 +0200
+++ trackdb/FormatOgg.cc	2010-06-06 16:48:23.000000000 +0200
@@ -84,6 +84,7 @@ FormatSupport::Status FormatOgg::oggInit
       return FS_WRONG_FORMAT;
   }
 
+  memset(&outFormat_, 0, sizeof(outFormat_));
   outFormat_.bits = 16;
   outFormat_.rate = 44100;
   outFormat_.channels = 2;
