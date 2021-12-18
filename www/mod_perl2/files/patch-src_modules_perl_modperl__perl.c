--- src/modules/perl/modperl_perl.c.orig	2019-10-05 11:04:42 UTC
+++ src/modules/perl/modperl_perl.c
@@ -268,7 +268,7 @@ void modperl_hash_seed_set(pTHX)
 #ifdef MP_NEED_HASH_SEED_FIXUP
     if (MP_init_hash_seed_set) {
 #if MP_PERL_VERSION_AT_LEAST(5, 17, 6)
-        memcpy(&PL_hash_seed, &MP_init_hash_seed,
+        memcpy(PL_hash_seed, &MP_init_hash_seed,
                 sizeof(PL_hash_seed) > sizeof(MP_init_hash_seed) ?
                     sizeof(MP_init_hash_seed) : sizeof(PL_hash_seed));
         PL_hash_seed_set   = MP_init_hash_seed_set;
