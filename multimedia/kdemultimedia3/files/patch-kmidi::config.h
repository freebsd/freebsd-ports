Apply a patch next. But this is not good solution, I think. I 
--- kmidi/config.h.orig	Thu Jun  7 03:55:40 2001
+++ kmidi/config.h	Mon Apr  1 20:53:28 2002
@@ -263,9 +263,12 @@
 	#if __FreeBSD_version <= 500000
 		#define XCHG_SHORT(x) __byte_swap_word(x)
 		#define XCHG_LONG(x) __byte_swap_long(x)
-	#else
+	#elif __FreeBSD_version <= 500031
 		#define XCHG_SHORT(x) __uint8_swap_uint16(x)
 		#define XCHG_LONG(x) __uint8_swap_uint32(x)
+	#else
+		#define XCHG_SHORT(x) __bswap16(x)
+		#define XCHG_LONG(x) __bswap32(x)
 	#endif
 #else
 	#define XCHG_SHORT(x) ((((x)&0xFF)<<8) | (((x)>>8)&0xFF))


