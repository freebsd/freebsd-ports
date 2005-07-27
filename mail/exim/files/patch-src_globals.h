
$FreeBSD$

--- src/globals.h.orig
+++ src/globals.h
@@ -659,9 +659,7 @@
 extern BOOL    split_spool_directory;  /* TRUE to use multiple subdirs */
 extern uschar *spool_directory;        /* Name of spool directory */
 #ifdef EXPERIMENTAL_SRS
-extern uschar *srs_config;             /* SRS config secret:max age:hash length:use timestamp:use hash */
-extern uschar *srs_db_address;         /* SRS db address */
-extern uschar *srs_db_key;             /* SRS db key */
+extern BOOL    srs_alwaysrewrite;      /* Rewrite for all domains */
 extern int     srs_hashlength;         /* SRS hash length */
 extern int     srs_hashmin;            /* SRS minimum hash length */
 extern int     srs_maxage;             /* SRS max age */
