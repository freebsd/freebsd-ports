--- modules/mod_authen/SS5Supa.c.orig	2011-08-26 12:28:01 UTC
+++ modules/mod_authen/SS5Supa.c
@@ -188,6 +188,7 @@ static unsigned char * ss5_secure_dh_compute_key (int 
         
   DH * ss = DH_new();
   BIGNUM * a = NULL;
+  BIGNUM *p, *g;
   int len = 1;
   unsigned char * public_key = NULL;
   uint32_t len_key = 0;
@@ -205,41 +206,75 @@ static unsigned char * ss5_secure_dh_compute_key (int 
   else
     pid=(UINT)pthread_self();
 
-  ss->p = BN_bin2bn ((pippo->p), pippo->lenp,  NULL);
-  ss->g = BN_bin2bn ((pippo->g), pippo->leng,  NULL);
+  p = BN_bin2bn ((pippo->p), pippo->lenp, NULL);
+  g = BN_bin2bn ((pippo->g), pippo->leng, NULL);
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+  DH_set0_pqg(ss, p, NULL, g);
+#else
+  ss->p = p;
+  ss->g = g;
+#endif
   a = BN_bin2bn ((pippo->a), pippo->lena,  NULL);
-  if (!a || !ss->p || !ss->g){
+  if (!a || !p || !g) {
     if( VERBOSE() ) {
       snprintf(logString,256 - 1,"[%u] [VERB] ss5_secure_dh_compute_key  - Error when compute a, p, g",pid);
       LOGUPDATE()
     }
+    BN_free(a);
+    BN_free(g);
+    BN_free(p);
+    DH_free(ss);
     return NULL;
   }       
   do {
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+    if (DH_get0_pub_key(ss)) {
+      BN_free(DH_get0_pub_key(ss));
+      BN_free(DH_get0_priv_key(ss));
+#else
     if (ss->pub_key){
       BN_free(ss->pub_key);
       BN_free(ss->priv_key);
+#endif
     }
     if ( DH_generate_key(ss) == 0){
       if( VERBOSE() ) {
         snprintf(logString,256 - 1,"[%u] [VERB] ss5_secure_dh_compute_key - Error when compute the keys",pid);
         LOGUPDATE()
       }
+      BN_free(a);
+      BN_free(g);
+      BN_free(p);
+      DH_free(ss);
       return NULL; 
     }
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+  } while (BN_is_negative(DH_get0_pub_key(ss)));
+
+  len_key = BN_num_bytes(DH_get0_pub_key(ss));
+#else
   }while(ss->pub_key->neg);
 
   len_key = BN_num_bytes(ss->pub_key);
+#endif
   public_key = malloc(len_key);
   if (!public_key){
     if( VERBOSE() ) {
       snprintf(logString,256 - 1,"[%u] [VERB] ss5_secure_dh_compute_key - malloc error",pid);
       LOGUPDATE()
     }
+    BN_free(a);
+    BN_free(g);
+    BN_free(p);
+    DH_free(ss);
     return NULL;
   }
 
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+  BN_bn2bin (DH_get0_pub_key(ss), public_key);
+#else
   BN_bn2bin (ss->pub_key, public_key);
+#endif
   ss5_create_dh_response(s, public_key, len_key);
 #if 0
   printf("B computed: len is %d\n",len_key);
@@ -256,6 +291,10 @@ static unsigned char * ss5_secure_dh_compute_key (int 
       snprintf(logString,256 - 1,"[%u] [VERB] ss5_secure_dh_compute_key - malloc error",pid);
       LOGUPDATE()
     }
+    BN_free(a);
+    BN_free(g);
+    BN_free(p);
+    DH_free(ss);
     return NULL;
   }
   bzero(session_key, DH_size (ss));
@@ -266,6 +305,10 @@ static unsigned char * ss5_secure_dh_compute_key (int 
     printf("%02x ", session_key[len]);
   printf("\n");
 #endif
+  BN_free(a);
+  BN_free(g);
+  BN_free(p);
+  DH_free(ss);
   return session_key;
 }
 
