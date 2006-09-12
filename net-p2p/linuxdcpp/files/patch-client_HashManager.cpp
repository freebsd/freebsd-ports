--- client/HashManager.cpp.orig	Mon Sep 11 22:01:37 2006
+++ client/HashManager.cpp	Mon Sep 11 22:02:43 2006
@@ -552,6 +552,10 @@
 
 #else // _WIN32
 
+#ifndef O_LARGEFILE
+#define O_LARGEFILE 0
+#endif
+
 static const int64_t BUF_SIZE = 0x1000000 - (0x1000000 % getpagesize());
 
 bool HashManager::Hasher::fastHash(const string& filename, u_int8_t* , TigerTree& tth, int64_t size, CRC32Filter* xcrc32) {
