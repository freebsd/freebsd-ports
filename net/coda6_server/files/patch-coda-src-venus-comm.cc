--- coda-src/venus/comm.cc.orig	Fri Aug  6 23:01:08 2004
+++ coda-src/venus/comm.cc	Fri Aug  6 23:02:04 2004
@@ -173,7 +173,7 @@
     sei.AckPoint = sftp_ackpoint;
     sei.PacketSize = sftp_packetsize;
     sei.EnforceQuota = 1;
-    sei.Port.Tag = (enum PortTag)0;
+    sei.Port.Tag = (PortTag)0;
     SFTP_Activate(&sei);
 
     /* RPC2 initialization. */
