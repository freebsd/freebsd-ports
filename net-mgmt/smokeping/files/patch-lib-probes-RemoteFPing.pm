--- lib/probes/RemoteFPing.pm.orig	Sun Jan 11 18:06:12 2004
+++ lib/probes/RemoteFPing.pm	Sun Jan 11 18:06:12 2004
@@ -8,7 +8,7 @@
 
  *** Probes ***
  + RemoteFPing
- binary = /usr/bin/ssh
+ binary = %%PREFIX%%/bin/ssh
  packetsize = 1024
  forks = 1
 
