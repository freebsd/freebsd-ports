--- gst-libs/ext/libav/libavcodec/arm/asm.S.orig	2013-02-02 09:03:32 UTC
+++ gst-libs/ext/libav/libavcodec/arm/asm.S
@@ -26,6 +26,22 @@
 #   define ELF @
 #endif
 
+#if   HAVE_NEON
+        .arch           armv7-a
+#elif HAVE_ARMV6T2
+        .arch           armv6t2
+#elif HAVE_ARMV6
+        .arch           armv6
+#elif HAVE_ARMV5TE
+        .arch           armv5te
+#endif
+
+#if   HAVE_NEON
+        .fpu            neon
+#elif HAVE_ARMVFP
+        .fpu            vfp
+#endif
+
         .syntax unified
 
 .macro  require8 val=1
