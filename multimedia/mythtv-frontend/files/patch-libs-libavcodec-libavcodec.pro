--- libs/libavcodec/libavcodec.pro.orig	2008-11-02 21:49:28.000000000 +0100
+++ libs/libavcodec/libavcodec.pro	2008-11-02 21:51:42.000000000 +0100
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
