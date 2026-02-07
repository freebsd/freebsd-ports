--- src/modules/perl/modperl_common_util.c.orig	2022-01-30 13:02:22 UTC
+++ src/modules/perl/modperl_common_util.c
@@ -41,7 +41,7 @@ int modperl_table_magic_copy(pTHX_ SV *sv, MAGIC *mg, 
 
 MP_INLINE static
 int modperl_table_magic_copy(pTHX_ SV *sv, MAGIC *mg, SV *nsv,
-                             const char *name, int namelen)
+                             const char *name, I32 namelen)
 {
     /* prefetch the value whenever we're iterating over the keys */
     MAGIC *tie_magic = mg_find(nsv, PERL_MAGIC_tiedelem);
