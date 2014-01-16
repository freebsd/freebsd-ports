--- ./addons/pvr.nextpvr/src/Socket.h.orig	2014-01-04 10:22:39.000000000 +0000
+++ ./addons/pvr.nextpvr/src/Socket.h	2014-01-13 18:52:05.000000000 +0000
@@ -85,7 +85,7 @@
 
 enum SocketDomain
 {
-  #if defined TARGET_LINUX || defined TARGET_DARWIN
+  #if defined TARGET_LINUX || defined TARGET_DARWIN || TARGET_FREEBSD
     pf_unix  = PF_UNIX,
     pf_local = PF_LOCAL,
   #endif
