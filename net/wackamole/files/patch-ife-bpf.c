--- ife-bpf.c.orig	2022-08-01 22:25:04 UTC
+++ ife-bpf.c
@@ -58,7 +58,7 @@ if_send_spoof_request(char *dev,
   static unsigned char my_mac[ETH_ALEN];
   static unsigned char bc_mac[ETH_ALEN] =
                 {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
-  memset(&ifr, sizeof(struct ifreq), 0);
+  memset(&ifr, 0, sizeof(struct ifreq));
   strncpy(ifr.ifr_name, dev, IFNAMSIZ);
   if (ioctl(_if_bpf, BIOCSETIF, (caddr_t)&ifr) < 0) {
      perror("ioctl (BIOCSETIF)");
