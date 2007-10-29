--- kopete/libkopete/avdevice/videocontrol.h.orig	2007-10-25 21:59:52.000000000 +0200
+++ kopete/libkopete/avdevice/videocontrol.h	2007-10-25 22:00:03.000000000 +0200
@@ -20,7 +20,11 @@
 #ifndef KOPETE_AVVIDEOCONTROL_H
 #define KOPETE_AVVIDEOCONTROL_H
 
-#include <asm/types.h>
+#include <sys/types.h>
+typedef int32_t __s32;
+typedef uint32_t __u32;
+typedef uint16_t __u16;
+typedef uint8_t __u8;
 #undef __STRICT_ANSI__
 #ifndef __u64 //required by videodev.h
 #define __u64 unsigned long long
