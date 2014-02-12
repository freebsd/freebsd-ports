--- ./src/net.cpp.orig	2013-10-29 13:38:10.000000000 +0000
+++ ./src/net.cpp	2014-01-18 23:12:20.911138205 +0000
@@ -51,7 +51,7 @@
 CAddress addrLocalHost("0.0.0.0", 0, false, nLocalServices);
 CNode* pnodeLocalHost = NULL;
 uint64 nLocalHostNonce = 0;
-array<int, 10> vnThreadsRunning;
+boost::array<int, 10> vnThreadsRunning;
 SOCKET hListenSocket = INVALID_SOCKET;
 
 vector<CNode*> vNodes;
@@ -1094,13 +1094,8 @@
         char intClient[16];
         char intPort[6];
 
-#if !defined(__WXMSW__) && !defined(MAC_OSX)
-        r = UPNP_AddPortMapping(urls.controlURL, data.first.servicetype,
-	                        port, port, lanaddr, 0, "TCP", 0);
-#else
         r = UPNP_AddPortMapping(urls.controlURL, data.first.servicetype,
 	                        port, port, lanaddr, 0, "TCP", 0, "0");
-#endif
         if(r!=UPNPCOMMAND_SUCCESS)
             printf("AddPortMapping(%s, %s, %s) failed with code %d (%s)\n",
                 port, port, lanaddr, r, strupnperror(r));
