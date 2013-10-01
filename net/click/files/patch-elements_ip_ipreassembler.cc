--- elements/ip/ipreassembler.cc.orig	2005-12-21 03:24:31.000000000 +0000
+++ elements/ip/ipreassembler.cc
@@ -27,6 +27,7 @@
 #include <click/error.hh>
 #include <click/glue.hh>
 #include <click/straccum.hh>
+#include <cstddef>
 CLICK_DECLS
 
 #define PACKET_CHUNK(p)		(((PacketInfo *)((p)->all_user_anno_u()))->chunk)
