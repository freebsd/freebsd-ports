
$FreeBSD$

--- src/globals.c.orig
+++ src/globals.c
@@ -1056,9 +1056,7 @@
 uschar *spool_directory        = US SPOOL_DIRECTORY
                            "\0<--------------Space to patch spool_directory->";
 #ifdef EXPERIMENTAL_SRS
-uschar *srs_config             = NULL;
-uschar *srs_db_address         = NULL;
-uschar *srs_db_key             = NULL;
+BOOL    srs_alwaysrewrite      = FALSE;
 int     srs_hashlength         = 6;
 int     srs_hashmin            = -1;
 int     srs_maxage             = 31;
