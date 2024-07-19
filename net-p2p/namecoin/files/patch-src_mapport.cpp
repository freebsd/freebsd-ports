--- src/mapport.cpp.orig	2022-11-21 07:35:21 UTC
+++ src/mapport.cpp
@@ -169,7 +169,11 @@ static bool ProcessUpnp()
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
