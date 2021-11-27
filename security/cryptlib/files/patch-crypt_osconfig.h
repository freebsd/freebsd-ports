--- crypt/osconfig.h.orig	2021-11-26 15:16:58 UTC
+++ crypt/osconfig.h
@@ -147,6 +147,10 @@
 	  #define L_ENDIAN
 	#else
 	  #define B_ENDIAN
+	#ifdef __LP64__
+	  #undef SIXTY_FOUR_BIT
+	  #define SIXTY_FOUR_BIT_LONG
+	#endif
 	#endif	/* Usually big-endian but may be little-endian */
 	#define BN_LLONG
 	#define DES_RISC1
