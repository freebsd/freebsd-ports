--- rays-filter.c.orig	2001-03-08 12:41:20 UTC
+++ rays-filter.c
@@ -65,8 +65,8 @@
 #include <sys/types.h>
 #include <unistd.h>
 #include <regex.h>
+#include <sysexits.h>
 #include "libmilter/mfapi.h" 
-#include "libmilter/milter.h"
 #include "rays-filter.h"
 
 
@@ -219,8 +219,10 @@
 #ifndef TRUE
 #define FALSE  0
 #define TRUE   1
+#ifndef __bool_true_false_are_defined
 typedef int bool;
 #endif
+#endif
 
 /* Data Structures
 **
@@ -326,6 +328,7 @@ static int open_log_file(struct mlfiPriv *priv)
       syslog(LOG_INFO, "Cannot allocate memory for log file name\n");
    else
    {
+#if 0
       if (mktemp(priv->mlfi_fname) == NULL)
          syslog(LOG_INFO, "Cannot make name for log file\n");
       else
@@ -334,6 +337,18 @@ static int open_log_file(struct mlfiPriv *priv)
          if (priv->mlfi_fname == NULL)
             syslog(LOG_INFO, "Cannot open log file\n");
       }
+#else
+      int handle;
+      handle = mkstemp(priv->mlfi_fname);
+      if (handle < 0)
+         syslog(LOG_INFO, "Cannot make name for log file\n");
+      else
+      {
+         priv->mlfi_fp = fdopen(handle, "w");
+         if ( priv->mlfi_fp == NULL )
+            syslog(LOG_INFO, "Cannot open log file\n");
+      }
+#endif
    }
    
    return 0;
@@ -489,7 +504,6 @@ sfsistat mlfi_header(SMFICTX *ctx, char *headerf, char
    */
 
    char  *headerf_uc = NULL; 
-   int   i = 0;
 
    if (MLFIPRIV->mlfi_fp != NULL)
       fprintf(MLFIPRIV->mlfi_fp, "%s: %s\r\n", headerf, headerv);
@@ -683,7 +697,7 @@ static int scan_header_block(SMFICTX *ctx, u_char *sta
    ** found, checks the header contents against the 'bad_string_list'
    */
 
-   char     *header, *end_of_header, *header_body;
+   char     *header, *header_body;
    char     header_name[HEADER_NAME_SIZE] = "\0";
    size_t   header_length = 0, name_length = 0, copy_length = 0;
    int      status = 0, is_end_of_headers = 0;
@@ -732,8 +746,6 @@ static int scan_buffer(SMFICTX *ctx)
    u_char  *header_block;
    u_char  *buffer = MLFIPRIV->buffer;
    char    *boundary = MLFIPRIV->boundary; 
-   size_t  i = 0;
-   size_t  used_buffer_length;
    int     status = 0;
 
    /* used_buffer_length = strlen(buffer);
@@ -742,7 +754,7 @@ static int scan_buffer(SMFICTX *ctx)
    */
   
    header_block = buffer; 
-   while (header_block = (u_char *)strstr(header_block, boundary))
+   while ((header_block = (u_char *)strstr(header_block, boundary)))
    { 
       status |= scan_header_block(ctx, header_block); 
       header_block++;
@@ -776,9 +788,9 @@ static int overlap_chunk(SMFICTX *ctx, u_char *bodyp, 
    }
    if (MLFIPRIV->mlfi_fp != NULL)
    {
-      fprintf(MLFIPRIV->mlfi_fp, "Overlap from previous: %7d\n",
+      fprintf(MLFIPRIV->mlfi_fp, "Overlap from previous: %7zu\n",
               overlap_size);
-      fprintf(MLFIPRIV->mlfi_fp, "Buffer contains:       %7d\n",
+      fprintf(MLFIPRIV->mlfi_fp, "Buffer contains:       %7zu\n",
               strlen(MLFIPRIV->buffer));
    }
 
@@ -802,7 +814,7 @@ static int store_overlap(SMFICTX *ctx, u_char *bodyp, 
    if (MLFIPRIV->mlfi_fp != NULL)
    {
       fprintf(MLFIPRIV->mlfi_fp, 
-              "Overlap to next chunk: %7d\n"
+              "Overlap to next chunk: %7zu\n"
               "=====================================================\n",
               strlen(MLFIPRIV->overlap));
    }
@@ -831,7 +843,7 @@ sfsistat mlfi_body(SMFICTX *ctx, u_char *bodyp, size_t
                  "\n=====================================================\n"
                  "Note inserted by " FILTER_SIGNATURE
                  "\n-----------------------------------------------------\n"
-                 "This chunk (bodylen):  %7d\n", bodylen);
+                 "This chunk (bodylen):  %7zu\n", bodylen);
       }
    }
 
