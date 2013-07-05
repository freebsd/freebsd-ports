--- src/vdpau_dump.c.orig	2012-10-05 17:02:58.000000000 +0200
+++ src/vdpau_dump.c	2013-07-05 10:12:10.976605992 +0200
@@ -59,8 +59,8 @@
         _(VAEncSequenceParameterBufferType);
         _(VAEncPictureParameterBufferType);
         _(VAEncSliceParameterBufferType);
-        _(VAEncH264VUIBufferType);
-        _(VAEncH264SEIBufferType);
+        // _(VAEncH264VUIBufferType);
+        // _(VAEncH264SEIBufferType);
 #endif
 #if VA_CHECK_VERSION(0,31,1)
         _(VAQMatrixBufferType);
