
$FreeBSD$

--- src/expand.c.orig
+++ src/expand.c
@@ -479,8 +479,6 @@
   { "spool_inodes",        vtype_pinodes,     (void *)TRUE },
   { "spool_space",         vtype_pspace,      (void *)TRUE },
 #ifdef EXPERIMENTAL_SRS
-  { "srs_db_address",      vtype_stringptr,   &srs_db_address },
-  { "srs_db_key",          vtype_stringptr,   &srs_db_key },
   { "srs_orig_recipient",  vtype_stringptr,   &srs_orig_recipient },
   { "srs_orig_sender",     vtype_stringptr,   &srs_orig_sender },
   { "srs_recipient",       vtype_stringptr,   &srs_recipient },
