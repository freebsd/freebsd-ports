--- src/gq-hash-openssl.c.orig	2008-01-09 14:55:46 UTC
+++ src/gq-hash-openssl.c
@@ -60,7 +60,7 @@ gq_hash_crypt(gchar const *data, gsize l
      salt->str[2] = 0;
 
      g_byte_array_append(gb, (guchar*)"{CRYPT}", 7);
-     des_fcrypt((gchar*)password, salt->str, (gchar*)cryptbuf);
+     DES_fcrypt((gchar*)password, salt->str, (gchar*)cryptbuf);
 
      g_byte_array_append(gb, cryptbuf, strlen((gchar*)cryptbuf));
 
@@ -242,7 +242,7 @@ static const char *lmhash_key = "KGS!@#$
 /* FIXME: silently assumes US-ASCII (or a single-byte encoding to be
    handled by toupper) */
 
-static void lm_make_key(const char *pw, des_cblock *key)
+static void lm_make_key(const char *pw, DES_cblock *key)
 {
      int i;
      char *k = (char *) key;
@@ -253,7 +253,7 @@ static void lm_make_key(const char *pw, 
 	  k[i+1]  = (pw[i] << (7 - i)) & 0xff;
      }
 
-     des_set_odd_parity(key);
+     DES_set_odd_parity(key);
 }
 
 GByteArray*
@@ -262,10 +262,10 @@ gq_hash_lmhash(gchar const* data, gsize 
      unsigned int i;
      char hex[2];
      char plain[15];
-     des_key_schedule schedule;
+     DES_key_schedule schedule;
      GByteArray *gb = NULL;
-     des_cblock ckey1, ckey2;
-     des_cblock bin1,  bin2;
+     DES_cblock ckey1, ckey2;
+     DES_cblock bin1,  bin2;
 
      memset(plain, 0, sizeof(plain));
 
@@ -274,12 +274,12 @@ gq_hash_lmhash(gchar const* data, gsize 
      }
 
      lm_make_key(plain, &ckey1);
-     des_set_key_unchecked(&ckey1, schedule);
-     des_ecb_encrypt((des_cblock*)lmhash_key, &bin1, schedule, DES_ENCRYPT);
+     DES_set_key_unchecked(&ckey1, &schedule);
+     DES_ecb_encrypt((DES_cblock*)lmhash_key, &bin1, &schedule, DES_ENCRYPT);
 
      lm_make_key(plain + 7, &ckey2);
-     des_set_key_unchecked(&ckey2, schedule);
-     des_ecb_encrypt((des_cblock*)lmhash_key, &bin2, schedule, DES_ENCRYPT);
+     DES_set_key_unchecked(&ckey2, &schedule);
+     DES_ecb_encrypt((DES_cblock*)lmhash_key, &bin2, &schedule, DES_ENCRYPT);
 
      gb = g_byte_array_new();
 
