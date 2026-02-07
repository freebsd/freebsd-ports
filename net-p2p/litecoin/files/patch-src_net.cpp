--- src/net.cpp.orig	2024-03-28 17:05:26 UTC
+++ src/net.cpp
@@ -1637,7 +1637,11 @@ static void ThreadMapPort()
     struct IGDdatas data;
     int r;
 
+#if MINIUPNPC_API_VERSION >= 18
+    r = UPNP_GetValidIGD(devlist, &urls, &data, lanaddr, sizeof(lanaddr), NULL, 0);
+#else
     r = UPNP_GetValidIGD(devlist, &urls, &data, lanaddr, sizeof(lanaddr));
+#endif
     if (r == 1)
     {
         if (fDiscover) {
