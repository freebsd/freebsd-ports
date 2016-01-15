This patch fixes a build with libpurple 2.0.12.

http://pidgin.im/pipermail/devel/2015-March/023639.html
Replaces the old emu with the _PASSIVE.
--- src/media-stream.c.orig	2016-01-11 12:37:14.015586000 +0100
+++ src/media-stream.c	2016-01-11 12:39:24.449684000 +0100
@@ -1076,7 +1076,7 @@
       if (proto == TP_MEDIA_STREAM_BASE_PROTO_UDP)
         protocol = PURPLE_MEDIA_NETWORK_PROTOCOL_UDP;
       else if (proto == TP_MEDIA_STREAM_BASE_PROTO_TCP)
-        protocol = PURPLE_MEDIA_NETWORK_PROTOCOL_TCP;
+        protocol = PURPLE_MEDIA_NETWORK_PROTOCOL_TCP_PASSIVE;
       else
         DEBUG ("Unknown network protocol");
 
