--- src/net.cpp.orig	2013-10-13 13:51:25 UTC
+++ src/net.cpp
@@ -58,7 +58,7 @@ static bool vfReachable[NET_MAX] = {};
 static bool vfLimited[NET_MAX] = {};
 static CNode* pnodeLocalHost = NULL;
 uint64 nLocalHostNonce = 0;
-array<int, THREAD_MAX> vnThreadsRunning;
+boost::array<int, THREAD_MAX> vnThreadsRunning;
 static std::vector<SOCKET> vhListenSocket;
 CAddrMan addrman;
 
@@ -1035,8 +1035,12 @@ void ThreadMapPort2(void* parg)
 #else
     /* miniupnpc 1.6 */
     int error = 0;
+#if MINIUPNPC_API_VERSION >= 14
+    devlist = upnpDiscover(2000, multicastif, minissdpdpath, 0, 0, 2, &error);
+#else
     devlist = upnpDiscover(2000, multicastif, minissdpdpath, 0, 0, &error);
 #endif
+#endif
 
     struct UPNPUrls urls;
     struct IGDdatas data;
