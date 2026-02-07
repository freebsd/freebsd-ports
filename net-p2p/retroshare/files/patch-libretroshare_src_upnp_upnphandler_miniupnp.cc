--- libretroshare/src/upnp/upnphandler_miniupnp.cc.orig	2018-03-13 19:25:38 UTC
+++ libretroshare/src/upnp/upnphandler_miniupnp.cc
@@ -116,9 +116,15 @@ bool upnphandler::initUPnPState()
 				   device->descURL, device->st);
 		}
 		putchar('\n');
+#if MINIUPNPC_API_VERSION >= 18
 		if(UPNP_GetValidIGD(upcd->devlist, &(upcd->urls),
 				&(upcd->data), upcd->lanaddr,
+				sizeof(upcd->lanaddr), NULL, 0))
+#else
+		if(UPNP_GetValidIGD(upcd->devlist, &(upcd->urls),
+				&(upcd->data), upcd->lanaddr,
 				sizeof(upcd->lanaddr)))
+#endif//>=18
 		{
 			printf("Found valid IGD : %s\n",
 					upcd->urls.controlURL);
