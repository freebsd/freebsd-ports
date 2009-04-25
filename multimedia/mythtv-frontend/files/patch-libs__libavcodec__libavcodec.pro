--- ./libs/libavcodec/libavcodec.pro.orig	2008-02-05 22:02:47.000000000 -0500
+++ ./libs/libavcodec/libavcodec.pro	2009-04-22 21:05:20.000000000 -0400
@@ -13,6 +13,10 @@
 DEFINES -= MMX
 DEFINES += HAVE_AV_CONFIG_H _LARGEFILE_SOURCE
 
+contains(ARCH_X86_64,yes) {
+	CFLAGS += -DBROKEN_RELOCATIONS
+}
+
 # Debug mode on x86 must compile without -fPIC and with -O, 
 # otherwise gcc runs out of registers.
 # libavcodec rev 7671 needs another register
