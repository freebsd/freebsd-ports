--- gst-libs/ext/libav/libavcodec/arm/asm.S.orig	2013-02-02 09:03:32 UTC
+++ gst-libs/ext/libav/libavcodec/arm/asm.S
@@ -28,6 +28,9 @@
 
         .syntax unified
 
+        .cpu    arm1176jzf-s
+        .fpu    vfpv2
+
 .macro  require8 val=1
 ELF     .eabi_attribute 24, \val
 .endm
