--- libtransmission/port-forwarding-upnp.cc.orig	2024-05-29 01:38:35 UTC
+++ libtransmission/port-forwarding-upnp.cc
@@ -275,8 +275,12 @@ tr_port_forwarding_state tr_upnpPulse(tr_upnp* handle,
 
         FreeUPNPUrls(&handle->urls);
         auto lanaddr = std::array<char, TR_ADDRSTRLEN>{};
-        if (UPNP_GetValidIGD(devlist, &handle->urls, &handle->data, std::data(lanaddr), std::size(lanaddr) - 1) ==
-            UPNP_IGD_VALID_CONNECTED)
+#if (MINIUPNPC_API_VERSION >= 18)
+        if (UPNP_GetValidIGD(devlist, &handle->urls, &handle->data, std::data(lanaddr), std::size(lanaddr) - 1, nullptr, 0)
+#else
+        if (UPNP_GetValidIGD(devlist, &handle->urls, &handle->data, std::data(lanaddr), std::size(lanaddr) - 1)
+#endif
+            == UPNP_IGD_VALID_CONNECTED)
         {
             tr_logAddInfo(fmt::format(_("Found Internet Gateway Device '{url}'"), fmt::arg("url", handle->urls.controlURL)));
             tr_logAddInfo(fmt::format(_("Local Address is '{address}'"), fmt::arg("address", lanaddr.data())));
