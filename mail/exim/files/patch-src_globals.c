
$FreeBSD$

--- src/globals.c.orig
+++ src/globals.c
@@ -1028,9 +1028,12 @@
 uschar *spool_directory        = US SPOOL_DIRECTORY
                            "\0<--------------Space to patch spool_directory->";
 #ifdef EXPERIMENTAL_SRS
-uschar *srs_config             = NULL;
-uschar *srs_db_address         = NULL;
-uschar *srs_db_key             = NULL;
+BOOL    srs_alwaysrewrite      = FALSE;
+int     srs_hashlength         = -1;
+int     srs_hashmin            = -1;
+int     srs_maxage             = -1;
+uschar *srs_secrets            = NULL;
+uschar *srs_separator          = NULL;
 uschar *srs_orig_recipient     = NULL;
 uschar *srs_orig_sender        = NULL;
 uschar *srs_recipient          = NULL;
