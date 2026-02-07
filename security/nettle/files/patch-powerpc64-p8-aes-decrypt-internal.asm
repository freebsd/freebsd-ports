--- powerpc64/p8/aes-decrypt-internal.asm.orig	2025-06-26 18:29:03 UTC
+++ powerpc64/p8/aes-decrypt-internal.asm
@@ -64,7 +64,7 @@ PROLOGUE(_nettle_aes_decrypt)
 
 define(`FUNC_ALIGN', `5')
 PROLOGUE(_nettle_aes_decrypt)
- DATA_LOAD_VEC(SWAP_MASK,.swap_mask,r5)
+ DATA_LOAD_VEC(SWAP_MASK,.swap_data,r5)
 
  subi ROUNDS,ROUNDS,1
  srdi LENGTH,LENGTH,4
@@ -269,6 +269,6 @@ EPILOGUE(_nettle_aes_decrypt)
 
  .data
  .align 4
-.swap_mask:
+.swap_data:
 IF_LE(`.byte 8,9,10,11,12,13,14,15,0,1,2,3,4,5,6,7')
 IF_BE(`.byte 3,2,1,0,7,6,5,4,11,10,9,8,15,14,13,12')
