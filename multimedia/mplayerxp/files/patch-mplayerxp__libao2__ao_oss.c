--- mplayerxp/libao2/ao_oss.c.orig	2005-07-02 18:59:01.000000000 +0900
+++ mplayerxp/libao2/ao_oss.c	2009-01-07 18:26:10.000000000 +0900
@@ -18,6 +18,22 @@
 #include "audio_out.h"
 #include "audio_out_internal.h"
 
+#ifndef DSP_CAP_COPROC
+#define DSP_CAP_COPROC 0x00000800
+#endif
+#ifndef DSP_CAP_TRIGGER
+#define DSP_CAP_TRIGGER 0x00001000
+#endif
+#ifndef DSP_CAP_MMAP
+#define DSP_CAP_MMAP 0x00002000
+#endif
+#ifndef DSP_CAP_MULTI
+#define DSP_CAP_MULTI 0x00004000
+#endif
+#ifndef DSP_CAP_BIND
+#define DSP_CAP_BIND  0x00008000
+#endif
+
 static ao_info_t info = 
 {
 	"OSS/ioctl audio output",
