--- GCrypt.xs.orig	2011-05-27 20:04:03 UTC
+++ GCrypt.xs
@@ -56,9 +56,13 @@
     int type;
     int action;
     gcry_cipher_hd_t h;
+/*
     gcry_ac_handle_t h_ac;
+*/
     gcry_md_hd_t h_md;
+/*
     gcry_ac_key_t key_ac;
+*/
     gcry_error_t err;
     int mode;
     int padding;
@@ -203,7 +207,9 @@
         char *s, *algo_s, *mode_s, *key_s;
         int i, algo, mode;
         unsigned int c_flags, ac_flags, md_flags;
+/*
         gcry_ac_id_t ac_algo;
+*/
         bool have_mode;
     CODE:
         New(0, RETVAL, 1, struct Crypt_GCrypt_s);
@@ -322,25 +328,19 @@
             if (!(algo = gcry_md_map_name(algo_s)))
                 croak("Unknown digest algorithm %s", algo_s);
 
-        RETVAL->err = gcry_md_open(&RETVAL->h_md, algo, md_flags);
+            RETVAL->err = gcry_md_open(&RETVAL->h_md, algo, md_flags);
             if (RETVAL->h_md == NULL) XSRETURN_UNDEF;
 
-        if (md_flags & GCRY_MD_FLAG_HMAC) {
-            /* what if this overwrites the earlier error value? */
-            RETVAL->err = gcry_md_setkey(RETVAL->h_md, key_s, RETVAL->keylen);
+            if (md_flags & GCRY_MD_FLAG_HMAC) {
+                /* what if this overwrites the earlier error value? */
+                RETVAL->err = gcry_md_setkey(RETVAL->h_md, key_s, RETVAL->keylen);
+            }
         }
-    }
         if (RETVAL->type == CG_TYPE_ASYMM) {
         
             croak("Asymmetric cryptography is not yet supported by Crypt::GCrypt");
+	    XSRETURN_UNDEF;
             
-            RETVAL->err = gcry_ac_name_to_id(algo_s, &ac_algo);
-            if (RETVAL->err)
-                croak("Unknown algorithm %s", algo_s);
-            
-            /* Init ac */
-            RETVAL->err = gcry_ac_open(&RETVAL->h_ac, ac_algo, ac_flags);
-            if (RETVAL->h_ac == NULL) XSRETURN_UNDEF;
         }
         
 
@@ -532,39 +532,6 @@
     OUTPUT:
         RETVAL
 
-SV *
-cg_sign(gcr, in)
-    Crypt_GCrypt gcr;
-    SV *in;
-    PREINIT:
-        gcry_mpi_t in_mpi, out_mpi;
-        gcry_ac_data_t outdata;
-        size_t len;
-        const void *inbuf;
-        const char *label;
-        char* outbuf;
-    CODE:
-        /*
-        in_mpi = gcry_mpi_new(0);
-        out_mpi = gcry_mpi_new(0);
-        inbuf = SvPV(in, len);
-        printf("inbuf: %s\n", inbuf);
-        gcry_mpi_scan( &in_mpi, GCRYMPI_FMT_STD, inbuf, strlen(inbuf), NULL );
-        printf("Key: %s\n", gcr->key_ac);
-        gcr->err = gcry_ac_data_sign(gcr->h_ac, gcr->key_ac, in_mpi, &outdata);
-        if (gcr->err) {
-            croak( gcry_strerror(gcr->err) );
-        }
-        printf("Here\n");
-        gcr->err = gcry_ac_data_get_index (outdata, 0, 0, &label, &out_mpi);
-        printf("Before (%s)\n", label);
-        gcry_mpi_print(GCRYMPI_FMT_STD, outbuf, 1024, NULL, out_mpi);
-        printf("After\n");
-        RETVAL = newSVpv(outbuf, 0);
-        */
-    OUTPUT:
-        RETVAL
-
 void
 cg_start(gcr, act)
     Crypt_GCrypt gcr;
@@ -594,8 +561,10 @@
     PREINIT:
         char *k, *s;
         char *mykey, *buf;
+/*
         gcry_ac_key_type_t keytype;
         gcry_ac_data_t keydata;
+*/
         gcry_mpi_t mpi;
         size_t len;
     CODE:
@@ -617,22 +586,7 @@
         
         /* Set key for asymmetric criptography */
         if (gcr->type == CG_TYPE_ASYMM) {
-            k = SvPV(ST(2), len);
-            
-            /* Key type */
-            keytype = -1;
-            s = SvPV(ST(1), len);
-            if (strcmp(s, "private") == 0) keytype = GCRY_AC_KEY_SECRET;
-            if (strcmp(s, "public") == 0) keytype = GCRY_AC_KEY_PUBLIC;
-            if (keytype == -1)
-                croak("Key must be private or public");
-            
-            gcry_control(GCRYCTL_INIT_SECMEM, strlen(k));
-            mpi = gcry_mpi_snew(0);
-            /* gcry_mpi_scan( &mpi, GCRYMPI_FMT_STD, k, NULL, NULL ); */
-            gcr->err = gcry_ac_data_new(&keydata);
-            gcr->err = gcry_ac_data_set(keydata, GCRY_AC_FLAG_COPY, "s", mpi);
-            gcr->err = gcry_ac_key_init(&gcr->key_ac, gcr->h_ac, keytype, keydata);
+            croak("Asymmetric cryptography is not yet supported by Crypt::GCrypt");
         }
 
 void
@@ -796,7 +750,9 @@
     Crypt_GCrypt gcr;
     CODE:
         if (gcr->type == CG_TYPE_CIPHER) gcry_cipher_close(gcr->h);
+/*
         if (gcr->type == CG_TYPE_ASYMM)  gcry_ac_close(gcr->h_ac);
+*/
         if (gcr->type == CG_TYPE_DIGEST) gcry_md_close(gcr->h_md);
         
         if (gcr->need_to_call_finish == 1)
