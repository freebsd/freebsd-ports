--- lib/probes/IOSPing.pm.orig	Sun Jan 11 18:06:12 2004
+++ lib/probes/IOSPing.pm	Sun Jan 11 18:06:12 2004
@@ -8,7 +8,7 @@
 
  *** Probes ***
  + IOSPing
- binary = /usr/bin/remsh
+ binary = %%PREFIX%%/bin/remsh
  packetsize = 1024
  forks = 1
 
@@ -27,8 +27,8 @@
 The binary and ioshost options are mandatory.
 
 The binary option specifies the path of the binary to be used to
-connect to the IOS device.  Commonly used binaries are /usr/bin/rsh
-and /usr/bin/remsh, although any script or binary should work if can
+connect to the IOS device.  Commonly used binaries are %%PREFIX%%/bin/rsh
+and %%PREFIX%%/bin/remsh, although any script or binary should work if can
 be called as 
 
     /path/to/binary [ -l user ] router ping
