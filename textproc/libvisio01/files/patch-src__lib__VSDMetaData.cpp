--- src/lib/VSDMetaData.cpp.orig	2015-01-01 16:11:45.000000000 -0500
+++ src/lib/VSDMetaData.cpp	2015-02-02 17:20:34.953039000 -0500
@@ -226,7 +226,7 @@
   uint64_t modifiedTime = readU64(input);
 
   // modifiedTime is number of 100ns since Jan 1 1601
-  static const uint64_t epoch = 11644473600;
+  static const uint64_t epoch = 11644473600ULL;
   time_t sec = (modifiedTime / 10000000) - epoch;
   const struct tm *time = localtime(&sec);
   if (time)
