
$FreeBSD$

--- src/globals.h.orig
+++ src/globals.h
@@ -631,13 +631,16 @@
 extern BOOL    split_spool_directory;  /* TRUE to use multiple subdirs */
 extern uschar *spool_directory;        /* Name of spool directory */
 #ifdef EXPERIMENTAL_SRS
-extern uschar *srs_config;             /* SRS config secret:max age:hash length:use timestamp:use hash */
-extern uschar *srs_db_address;         /* SRS db address */
-extern uschar *srs_db_key;             /* SRS db key */
+extern BOOL    srs_alwaysrewrite;      /* Rewrite for all domains */
+extern int     srs_hashlength;         /* Hash length to generate */
+extern int     srs_hashmin;            /* Hash length to check */
+extern int     srs_maxage;             /* Max age for SRS address */
+extern uschar *srs_secrets;            /* List of SRS secrets */
+extern uschar *srs_separator;          /* Separator for SRS addresses */
 extern uschar *srs_orig_sender;        /* SRS original sender */
 extern uschar *srs_orig_recipient;     /* SRS original recipient */
 extern uschar *srs_recipient;          /* SRS recipient */
-extern uschar *srs_status;             /* SRS staus */
+extern uschar *srs_status;             /* SRS status */
 #endif
 extern int     string_datestamp_offset;/* After insertion by string_format */
 extern BOOL    strip_excess_angle_brackets; /* Surrounding route-addrs */
