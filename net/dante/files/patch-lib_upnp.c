--- lib/upnp.c.orig	2020-11-11 16:11:55 UTC
+++ lib/upnp.c
@@ -208,7 +208,11 @@ socks_initupnp(gw, emsg, emsglen)
          socks_autoadd_directroute(&commands, &protocols, &saddr, &smask);
       }
 
-      devtype = UPNP_GetValidIGD(dev, &url, &data, myaddr, sizeof(myaddr));
+      devtype = UPNP_GetValidIGD(dev, &url, &data, myaddr, sizeof(myaddr)
+#if MINIUPNPC_API_VERSION > 17
+      , NULL, 0
+#endif
+      );
       switch (devtype) {
          case UPNP_NO_IGD:
             snprintf(emsg, emsglen, "no UPNP IGD discovered on local network");
