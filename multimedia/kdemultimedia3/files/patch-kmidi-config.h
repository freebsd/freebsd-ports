--- ./kmidi/config.h.old	Sun Apr 28 23:33:03 2002
+++ ./kmidi/config.h	Sun Apr 28 23:33:55 2002
@@ -264,8 +264,8 @@
 		#define XCHG_SHORT(x) __byte_swap_word(x)
 		#define XCHG_LONG(x) __byte_swap_long(x)
 	#else
-		#define XCHG_SHORT(x) __uint8_swap_uint16(x)
-		#define XCHG_LONG(x) __uint8_swap_uint32(x)
+		#define XCHG_SHORT(x) __bswap16(x)
+		#define XCHG_LONG(x) __bswap32(x)
 	#endif
 #else
 	#define XCHG_SHORT(x) ((((x)&0xFF)<<8) | (((x)>>8)&0xFF))
