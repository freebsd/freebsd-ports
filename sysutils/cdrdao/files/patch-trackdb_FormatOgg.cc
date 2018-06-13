--- trackdb/FormatOgg.cc.orig	2018-05-15 13:30:52 UTC
+++ trackdb/FormatOgg.cc
@@ -84,6 +84,7 @@ FormatSupport::Status FormatOgg::oggInit
       return FS_WRONG_FORMAT;
   }
 
+  memset(&outFormat_, 0, sizeof(outFormat_));
   outFormat_.bits = 16;
   outFormat_.rate = 44100;
   outFormat_.channels = 2;
