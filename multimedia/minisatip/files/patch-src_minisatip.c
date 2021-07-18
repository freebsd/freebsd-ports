--- src/minisatip.c.orig	2021-07-05 22:02:32 UTC
+++ src/minisatip.c
@@ -1827,11 +1827,15 @@ int main(int argc, char *argv[]) {
 		struct ifreq ifr;
 		memset(&ifr, 0, sizeof(ifr));
 		snprintf(ifr.ifr_name, sizeof(ifr.ifr_name), "%s", opts.bind_dev);
+#if defined(SO_BINDTODEVICE)
   	    	if (setsockopt(ssdp, SOL_SOCKET, SO_BINDTODEVICE, (void *)&ifr, sizeof(ifr)) < 0)
 			LOG("SSDP: Failed to set SO_BINDTODEVICE to %s", opts.bind_dev);
   	    	if (setsockopt(ssdp1, SOL_SOCKET, SO_BINDTODEVICE, (void *)&ifr, sizeof(ifr)) < 0)
 			LOG("SSDP: Failed to set SO_BINDTODEVICE to %s", opts.bind_dev);
 		LOG("SSDP: Bound to device %s", opts.bind_dev);
+#else
+		LOG("SSDP: Binding to device with SO_BINDTODEVICE not supported!");
+#endif
 	}
 
         si = sockets_add(ssdp, NULL, -1, TYPE_UDP, (socket_action)ssdp_reply,
