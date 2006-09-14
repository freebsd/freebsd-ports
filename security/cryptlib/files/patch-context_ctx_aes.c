--- context/ctx_aes.c.orig	Thu Sep 14 20:29:24 2006
+++ context/ctx_aes.c	Thu Sep 14 20:30:14 2006
@@ -67,10 +67,10 @@
    is a relatively minor overhead compared to en/decryption, so it's not a 
    big problem) */
 
+#define L_SIZE( x )		( sizeof( x ) / sizeof( unsigned long ) )	
 #if defined( USE_VIA_ACE_IF_PRESENT )
   /* Data is DWORD-aligned anyway but we need to have 16-byte alignment for
      key data in case we're using the VIA ACE */
-  #define L_SIZE( x )		( sizeof( x ) / sizeof( unsigned long ) )	
   #define KS_SIZE			( sizeof( AES_EKEY ) + sizeof( AES_DKEY ) + 24 )
   #define ALGN( x )			( ( unsigned long )( x ) & 0xFFFFFFF0 )
   #define EKEY( x )			( ( AES_EKEY * ) ALGN( ( ( AES_CTX * ) x )->ksch + 3 ) )
