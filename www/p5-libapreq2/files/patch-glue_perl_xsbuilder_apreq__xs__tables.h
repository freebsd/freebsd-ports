--- glue/perl/xsbuilder/apreq_xs_tables.h.orig	2022-08-18 09:18:20 UTC
+++ glue/perl/xsbuilder/apreq_xs_tables.h
@@ -42,7 +42,7 @@ static int apreq_xs_cookie_table_magic_copy(pTHX_ SV *
  */
 
 static int apreq_xs_cookie_table_magic_copy(pTHX_ SV *sv, MAGIC *mg, SV *nsv,
-                                            const char *name, int namelen)
+                                            const char *name, I32 namelen)
 {
     /* Prefetch the value whenever the table iterator is > 0 */
     MAGIC *tie_magic = mg_find(nsv, PERL_MAGIC_tiedelem);
@@ -151,7 +151,7 @@ static int apreq_xs_param_table_magic_copy(pTHX_ SV *s
  */
 
 static int apreq_xs_param_table_magic_copy(pTHX_ SV *sv, MAGIC *mg, SV *nsv,
-                                  const char *name, int namelen)
+                                  const char *name, I32 namelen)
 {
     /* Prefetch the value whenever the table iterator is > 0 */
     MAGIC *tie_magic = mg_find(nsv, PERL_MAGIC_tiedelem);
