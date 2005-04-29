
$FreeBSD$

--- src/readconf.c.orig
+++ src/readconf.c
@@ -333,7 +333,12 @@
   { "split_spool_directory",    opt_bool,        &split_spool_directory },
   { "spool_directory",          opt_stringptr,   &spool_directory },
 #ifdef EXPERIMENTAL_SRS
-  { "srs_config",               opt_stringptr,   &srs_config },
+  { "srs_alwaysrewrite",        opt_bool,        &srs_alwaysrewrite },
+  { "srs_hashlength",           opt_int,         &srs_hashlength },
+  { "srs_hashmin",              opt_int,         &srs_hashmin },
+  { "srs_maxage",               opt_int,         &srs_maxage },
+  { "srs_secrets",              opt_stringptr,   &srs_secrets },
+  { "srs_separator",            opt_stringptr,   &srs_separator },
 #endif
   { "strip_excess_angle_brackets", opt_bool,     &strip_excess_angle_brackets },
   { "strip_trailing_dot",       opt_bool,        &strip_trailing_dot },
