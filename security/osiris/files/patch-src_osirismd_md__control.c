--- src/osirismd/md_control.c.orig	2006-12-05 12:02:48 UTC
+++ src/osirismd/md_control.c
@@ -3259,9 +3259,9 @@ osi_bool generate_session_key_hash( unsi
             int index;
             char checksum[41];
 
-            SHA_Init( &context );
-            SHA_Update( &context, key, (unsigned long)keysize );
-            SHA_Final( &( digest[0] ), &context );
+            SHA1_Init( &context );
+            SHA1_Update( &context, key, (unsigned long)keysize );
+            SHA1_Final( &( digest[0] ), &context );
 
             for ( index = 0; index < SHA_DIGEST_LENGTH; index++ )
             {
