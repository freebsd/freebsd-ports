--- send_packet_bsd.c.orig	2009-05-04 16:27:55.000000000 -0700
+++ send_packet_bsd.c	2009-05-04 16:28:43.000000000 -0700
@@ -56,7 +56,13 @@
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
