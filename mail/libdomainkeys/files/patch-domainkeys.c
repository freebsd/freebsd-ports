Adapted from
http://git.pld-linux.org/?p=packages/libdomainkeys.git;a=blob;f=openssl.patch;h=a79c3f6b9431bb339b21937a54ce42c944f67090;hb=0b35df2ead77bfee132c88109c001ba079da27cd

--- domainkeys.c.orig	2008-03-31 22:50:39 UTC
+++ domainkeys.c
@@ -120,7 +120,11 @@ typedef struct
 {
 /* STARTPRIV */
   int dkmarker;     /* in case somebody casts in */
+#if OPENSSL_VERSION_NUMBER < 0x10100001L
   EVP_MD_CTX mdctx;   /* the hash */
+#else
+  EVP_MD_CTX *mdctx;  /* the hash */
+#endif
   int signing;      /* our current signing/verifying state */
   int in_headers;   /* true if we're still processing headers */
   char *header;     /* points to a malloc'ed block for header. */
@@ -503,7 +507,24 @@ DK *dk_sign(DK_LIB *dklib, DK_STAT *statp, int canon)
     return NULL;
   }
   dk->canon = canon; /* TC13-simple, TC13-nofws */
-  EVP_SignInit(&dk->mdctx, dklib->md);
+#if OPENSSL_VERSION_NUMBER < 0x10100001L
+  if (!EVP_SignInit(&dk->mdctx, dklib->md)) {
+    if (statp)
+    {
+      *statp = DKERR(DK_STAT_NORESOURCE);
+    }
+    return NULL;
+  }
+#else
+  dk->mdctx = EVP_MD_CTX_create();
+  if (!dk->mdctx || !EVP_SignInit(dk->mdctx, dklib->md)) {
+    if (statp)
+    {
+      *statp = DKERR(DK_STAT_NORESOURCE);
+    }
+    return NULL;
+  }
+#endif
 
   if (statp)
   {
@@ -541,7 +562,24 @@ DK *dk_verify(DK_LIB *dklib, DK_STAT *statp)
     }
     return NULL;
   }
-  EVP_VerifyInit(&dk->mdctx, dklib->md);
+#if OPENSSL_VERSION_NUMBER < 0x10100001L
+  if (!EVP_VerifyInit(&dk->mdctx, dklib->md)) {
+    if (statp)
+    {
+      *statp = DKERR(DK_STAT_NORESOURCE);
+    }
+    return NULL;
+  }
+#else
+  dk->mdctx = EVP_MD_CTX_create();
+  if (!dk->mdctx || !EVP_VerifyInit(dk->mdctx, dklib->md)) {
+    if (statp)
+    {
+      *statp = DKERR(DK_STAT_NORESOURCE);
+    }
+    return NULL;
+  }
+#endif
 
   if (statp)
   {
@@ -928,14 +966,22 @@ static void dkhash(DK *dk, const unsigned char *ptr)
     {
 
 #ifndef DK_HASH_BUFF
+#if OPENSSL_VERSION_NUMBER < 0x10100001L
       EVP_DigestUpdate(&dk->mdctx, "\r\n", 2);
 #else
+      EVP_DigestUpdate(dk->mdctx, "\r\n", 2);
+#endif
+#else
       /* buffer hack */
       dk->hash_buff[dk->hash_buff_len++] = '\r';
       dk->hash_buff[dk->hash_buff_len++] = '\n';
       if (dk->hash_buff_len >= (DK_BLOCK - 1))
       {
+#if OPENSSL_VERSION_NUMBER < 0x10100001L
         EVP_DigestUpdate(&dk->mdctx, dk->hash_buff, dk->hash_buff_len);
+#else
+        EVP_DigestUpdate(dk->mdctx, dk->hash_buff, dk->hash_buff_len);
+#endif
         dk->hash_buff_len = 0;
       }
       /* buffer hack */
@@ -955,13 +1001,21 @@ static void dkhash(DK *dk, const unsigned char *ptr)
       if (dk->canon == DK_CANON_SIMPLE)//if nofws we ignore \r
       {
 #ifndef DK_HASH_BUFF
+#if OPENSSL_VERSION_NUMBER < 0x10100001L
         EVP_DigestUpdate(&dk->mdctx, "\r", 1);
 #else
+        EVP_DigestUpdate(dk->mdctx, "\r", 1);
+#endif
+#else
         /* buffer hack */
         dk->hash_buff[dk->hash_buff_len++] = '\r';
         if (dk->hash_buff_len >= (DK_BLOCK - 1))
         {
+#if OPENSSL_VERSION_NUMBER < 0x10100001L
           EVP_DigestUpdate(&dk->mdctx, dk->hash_buff, dk->hash_buff_len);
+#else
+          EVP_DigestUpdate(dk->mdctx, dk->hash_buff, dk->hash_buff_len);
+#endif
           dk->hash_buff_len = 0;
         }
         /* buffer hack */
@@ -977,13 +1031,21 @@ static void dkhash(DK *dk, const unsigned char *ptr)
       dk->state --;
     }
 #ifndef DK_HASH_BUFF
+#if OPENSSL_VERSION_NUMBER < 0x10100001L
     EVP_DigestUpdate(&dk->mdctx, ptr, 1);
 #else
+    EVP_DigestUpdate(dk->mdctx, ptr, 1);
+#endif
+#else
     /* buffer hack */
     dk->hash_buff[dk->hash_buff_len++] = *ptr;
     if (dk->hash_buff_len >= (DK_BLOCK - 1))
     {
+#if OPENSSL_VERSION_NUMBER < 0x10100001L
       EVP_DigestUpdate(&dk->mdctx, dk->hash_buff, dk->hash_buff_len);
+#else
+      EVP_DigestUpdate(dk->mdctx, dk->hash_buff, dk->hash_buff_len);
+#endif
       dk->hash_buff_len = 0;
     }
     /* buffer hack */
@@ -1746,11 +1808,19 @@ DK_STAT dk_end(DK *dk, DK_FLAGS *dkf)
     //clean out hash buffer
     dk->hash_buff[dk->hash_buff_len++] = '\r';
     dk->hash_buff[dk->hash_buff_len++] = '\n';
+#if OPENSSL_VERSION_NUMBER < 0x10100001L
     EVP_DigestUpdate(&dk->mdctx, dk->hash_buff, dk->hash_buff_len);
+#else
+    EVP_DigestUpdate(dk->mdctx, dk->hash_buff, dk->hash_buff_len);
+#endif
     dk->hash_buff_len = 0;
 #else
+#if OPENSSL_VERSION_NUMBER < 0x10100001L
     EVP_DigestUpdate(&dk->mdctx, "\r\n", 2);
+#else
+    EVP_DigestUpdate(dk->mdctx, "\r\n", 2);
 #endif
+#endif
 #ifdef DK_DEBUG
     fprintf(stderr,"\r\n");
 #endif
@@ -1949,7 +2019,11 @@ DK_STAT dk_end(DK *dk, DK_FLAGS *dkf)
       }
 
       /* using that key, verify that the digest is properly signed */
+#if OPENSSL_VERSION_NUMBER < 0x10100001L
       i = EVP_VerifyFinal(&dk->mdctx, md_value, md_len, publickey);
+#else
+      i = EVP_VerifyFinal(dk->mdctx, md_value, md_len, publickey);
+#endif
 
       if (i > 0)
       {
@@ -2058,7 +2132,11 @@ DK_STAT dk_getsig(DK *dk, void *privatekey, unsigned c
 
       siglen = EVP_PKEY_size(pkey);
       sig = (unsigned char*) OPENSSL_malloc(siglen);
+#if OPENSSL_VERSION_NUMBER < 0x10100001L
       EVP_SignFinal(&dk->mdctx, sig, &siglen, pkey);
+#else
+      EVP_SignFinal(dk->mdctx, sig, &siglen, pkey);
+#endif
       EVP_PKEY_free(pkey);
 
       bio = BIO_new(BIO_s_mem());
@@ -2152,7 +2230,11 @@ DK_STAT dk_free(DK *dk, int doClearErrState)
 #ifdef DK_HASH_BUFF
   DK_MFREE(dk->hash_buff);
 #endif
+#if OPENSSL_VERSION_NUMBER < 0x10100001L
   EVP_MD_CTX_cleanup(&dk->mdctx);
+#else
+  EVP_MD_CTX_free(dk->mdctx);
+#endif
   DK_MFREE(dk->header);   /* alloc'ing dk->header is not optional. */
   dk->dkmarker = ~DKMARK;
   DK_MFREE(dk);
