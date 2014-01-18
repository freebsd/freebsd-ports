--- src/net.cpp.orig	2014-01-18 04:31:19.000000000 +0000
+++ src/net.cpp	2014-01-18 04:32:57.000000000 +0000
@@ -58,7 +58,7 @@
 static bool vfLimited[NET_MAX] = {};
 static CNode* pnodeLocalHost = NULL;
 uint64 nLocalHostNonce = 0;
-array<int, THREAD_MAX> vnThreadsRunning;
+boost::array<int, THREAD_MAX> vnThreadsRunning;
 static std::vector<SOCKET> vhListenSocket;
 CAddrMan addrman;
 
