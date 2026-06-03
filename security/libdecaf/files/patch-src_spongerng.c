--- src/spongerng.c.orig	2026-05-04 07:41:21 UTC
+++ src/spongerng.c
@@ -122,7 +122,7 @@ void decaf_spongerng_next (
     decaf_sha3_update(prng->sponge,lenx,sizeof(lenx));
     decaf_sha3_output(prng->sponge,out,len);
     
-    const uint8_t nope;
+    const uint8_t nope = 0;
     decaf_spongerng_stir(prng,&nope,0);
 }
 
@@ -204,7 +204,7 @@ decaf_error_t decaf_spongerng_init_from_file (
 #if defined _MSC_VER
     }
 #endif /* _MSC_VER */
-    const uint8_t nope;
+    const uint8_t nope = 0;
     decaf_spongerng_stir(prng,&nope,0);
     
     return DECAF_SUCCESS;
