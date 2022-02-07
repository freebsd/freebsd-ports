--- src/minisatip.c.orig	2022-02-04 06:56:09 UTC
+++ src/minisatip.c
@@ -1871,6 +1871,7 @@ int main(int argc, char *argv[]) {
             struct ifreq ifr;
             memset(&ifr, 0, sizeof(ifr));
             snprintf(ifr.ifr_name, sizeof(ifr.ifr_name), "%s", opts.bind_dev);
+#if defined(SO_BINDTODEVICE)
             if (setsockopt(ssdp, SOL_SOCKET, SO_BINDTODEVICE, (void *)&ifr,
                            sizeof(ifr)) < 0)
                 LOG("SSDP: Failed to set SO_BINDTODEVICE to %s", opts.bind_dev);
@@ -1878,6 +1879,9 @@ int main(int argc, char *argv[]) {
                            sizeof(ifr)) < 0)
                 LOG("SSDP: Failed to set SO_BINDTODEVICE to %s", opts.bind_dev);
             LOG("SSDP: Bound to device %s", opts.bind_dev);
+#else
+            LOG("SSDP: Binding to device with SO_BINDTODEVICE not supported!");
+#endif
         }
 
         si = sockets_add(ssdp, NULL, -1, TYPE_UDP, (socket_action)ssdp_reply,
