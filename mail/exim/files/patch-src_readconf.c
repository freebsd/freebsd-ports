
$FreeBSD$

--- src/readconf.c.orig
+++ src/readconf.c
@@ -340,7 +340,7 @@
   { "split_spool_directory",    opt_bool,        &split_spool_directory },
   { "spool_directory",          opt_stringptr,   &spool_directory },
 #ifdef EXPERIMENTAL_SRS
-  { "srs_config",               opt_stringptr,   &srs_config },
+  { "srs_alwaysrewrite",        opt_bool,        &srs_alwaysrewrite },
   { "srs_hashlength",           opt_int,         &srs_hashlength },
   { "srs_hashmin",              opt_int,         &srs_hashmin },
   { "srs_maxage",               opt_int,         &srs_maxage },
