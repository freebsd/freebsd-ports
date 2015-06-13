--- send_packet_bsd.c.orig	2009-05-23 11:11:58 UTC
+++ send_packet_bsd.c
@@ -56,7 +56,13 @@ int send_packet_bsd(const char *dev, u_c
       flock(bpffd,LOCK_EX);
       
       // Bind it to a device
-      ioctl(bpffd,BIOCSETIF,dev);
+      if (ioctl(bpffd,BIOCSETIF,dev) == -1)
+      {
+	flock(bpffd,LOCK_UN);
+	close(bpffd);
+	perror("open bpf");
+	return 0;
+      }
       
       // Send the packet and unlock
       write(bpffd,packet,packetsize);
