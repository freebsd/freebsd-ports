--- sha1.h.orig
+++ sha1.h
@@ -36,8 +36,6 @@
         (ctx)->num = 0l				\
     } while (0)
 
-#define SHA1_Transform( iv, data ) SHA1_Xform( iv, data )
-
 #else
 
 typedef struct {
@@ -60,9 +58,12 @@
 
 #endif
 
-void SHA1_Xform( word32[ SHA1_DIGEST_WORDS ], 
+void SHA1_Xform( word32[ SHA1_DIGEST_WORDS ],
 		 const byte[ SHA1_INPUT_BYTES ] );
 
+void SHA1_Transform( word32[ SHA1_DIGEST_WORDS ],
+		     const byte[ SHA1_INPUT_BYTES ] );
+
 #if defined( __cplusplus )
 }
 #endif
