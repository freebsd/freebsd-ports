--- src/lib/MSPUBMetaData.cpp.orig	2014-12-30 06:42:44.000000000 -0500
+++ src/lib/MSPUBMetaData.cpp	2015-02-02 17:30:18.706664000 -0500
@@ -210,7 +210,7 @@
   uint64_t modifiedTime = readU64(input);
 
   // modifiedTime is number of 100ns since Jan 1 1601
-  static const uint64_t epoch = 11644473600;
+  static const uint64_t epoch = 11644473600ULL;
   time_t sec = (modifiedTime / 10000000) - epoch;
   const struct tm *time = localtime(&sec);
   if (time)
