--- client/ntlmauth.c.orig	2009-02-05 15:32:12 UTC
+++ client/ntlmauth.c
@@ -56,7 +56,7 @@ extern int write_timeout(int s,  char *b
 extern int read_timeout(int s, char *buffer, int size, int tmo);
 extern void do_log( int prio, char *format , ...);
 
-static void setup_des_key(unsigned char *key56, des_key_schedule *ks);
+static void setup_des_key(unsigned char *key56, DES_key_schedule *ks);
 static void calc_resp(unsigned char *keys, unsigned char *plaintext, unsigned char *results);
 static char *do_ntlm_auth_1(char *username, char *password);
 static char *do_ntlm_auth_2(iconv_t myiconv, char *username, char *password, char *challenge);
@@ -156,8 +156,8 @@ static char *do_ntlm_auth_2(iconv_t myic
   unsigned char  *nt_pw = NULL,*lm_resp,*nt_resp;
   const unsigned char magic[] = "KGS!@#$%";
   unsigned char lm_hpw[50];
-  des_key_schedule ks1;
-  des_key_schedule ks2;
+  DES_key_schedule ks1;
+  DES_key_schedule ks2;
   unsigned char nt_hpw[50];
   MD4_CTX context;
   unsigned short server_flags;
@@ -558,9 +558,9 @@ catch:
  * turns a 56 bit key into the 64 bit, odd parity key and sets the key.
  * The key schedule ks is also set.
  */
-static void setup_des_key(unsigned char key_56[], des_key_schedule *ks)
+static void setup_des_key(unsigned char key_56[], DES_key_schedule *ks)
 {
-    des_cblock key;
+    DES_cblock key;
 
     key[0] = key_56[0];
     key[1] = ((key_56[0] << 7) & 0xFF) | (key_56[1] >> 1);
@@ -582,7 +582,7 @@ static void setup_des_key(unsigned char 
  */
 static void calc_resp(unsigned char *keys, unsigned char *plaintext, unsigned char *results)
 {
-    des_key_schedule ks;
+    DES_key_schedule ks;
 
     setup_des_key(keys, &ks);
     DES_ecb_encrypt((const_DES_cblock *) plaintext, (const_DES_cblock *) results, &ks, DES_ENCRYPT);
