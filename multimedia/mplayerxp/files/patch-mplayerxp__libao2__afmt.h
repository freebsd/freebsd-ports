--- mplayerxp/libao2/afmt.h.orig	Wed Oct 20 15:00:03 2004
+++ mplayerxp/libao2/afmt.h	Sun Oct  1 21:44:02 2006
@@ -30,12 +30,30 @@
 #	define AFMT_AC3			0x00000400	/* Dolby Digital AC3 */
 #endif
 
+/* 24 bit formats from the linux kernel */
+#ifndef AFMT_S24_LE
+
+// FreeBSD fix...
+#if AFMT_S32_LE == 0x1000
+
+#	define AFMT_S24_LE		0x00010000
+#	define AFMT_S24_BE		0x00020000
+#	define AFMT_U24_LE		0x00040000
+#	define AFMT_U24_BE		0x00080000
+
+#else
+
+#	define AFMT_S24_LE		0x00000800
+#	define AFMT_S24_BE		0x00001000
+#	define AFMT_U24_LE		0x00002000
+#	define AFMT_U24_BE		0x00004000
+
+#endif
+
+#endif
+
 /* 32 bit formats (MSB aligned) formats */
 #ifndef AFMT_S32_LE
-#	define AFMT_S24_LE	        0x00000800
-#	define AFMT_S24_BE	        0x00001000
-#	define AFMT_U24_LE	        0x00002000
-#	define AFMT_U24_BE	        0x00004000
 #	define AFMT_S32_LE	        0x00008000
 #	define AFMT_S32_BE	        0x00010000
 #	define AFMT_U32_LE	        0x00020000
