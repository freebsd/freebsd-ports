--- kmidi/config.h.orig	Sun Oct 21 20:07:36 2001
+++ kmidi/config.h	Wed May 22 10:37:04 2002
@@ -261,11 +261,16 @@
 	/* And a better idea would be to attempt the various asm 
 	optimizations ourselves IMO, but hey, this is free */
 	#if __FreeBSD_version <= 500000
+#if defined (__i386__)
 		#define XCHG_SHORT(x) __byte_swap_word(x)
 		#define XCHG_LONG(x) __byte_swap_long(x)
+#else
+		#define XCHG_SHORT(x) htons(x)
+		#define XCHG_LONG(x) htonl(x)
+#endif
 	#else
-		#define XCHG_SHORT(x) __uint8_swap_uint16(x)
-		#define XCHG_LONG(x) __uint8_swap_uint32(x)
+		#define XCHG_SHORT(x) __bswap16(x)
+		#define XCHG_LONG(x) __bswap32(x)
 	#endif
 #else
 	#define XCHG_SHORT(x) ((((x)&0xFF)<<8) | (((x)>>8)&0xFF))
