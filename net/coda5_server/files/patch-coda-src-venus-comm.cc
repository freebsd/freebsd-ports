--- coda-src/venus/comm.cc.orig	Fri Aug  6 23:32:52 2004
+++ coda-src/venus/comm.cc	Fri Aug  6 23:33:07 2004
@@ -245,7 +245,7 @@
     sei.PacketSize = sftp_packetsize;
     sei.EnforceQuota = 1;
 
-    sei.Port.Tag = (enum PortTag)0;
+    sei.Port.Tag = (PortTag)0;
     if (!masquerade) {
         sei.Port.Tag = RPC2_PORTBYINETNUMBER;
 
