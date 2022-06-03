--- send_packet_bsd.c.orig	2022-05-11 08:27:25 UTC
+++ send_packet_bsd.c
@@ -60,7 +60,13 @@ int send_packet_bsd(const char *dev, u_char *packet, u
     flock(bpffd, LOCK_EX);
       
     // Bind it to a device
-    ioctl(bpffd, BIOCSETIF, dev);
+    if (ioctl(bpffd, BIOCSETIF, dev) == -1)
+    {
+      flock(bpffd, LOCK_UN);
+      close(bpffd);
+      perror("open bpf");
+      return 0;
+    }
       
     // Send the packet and unlock
     write(bpffd, packet, packetsize);
