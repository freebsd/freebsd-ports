--- src/ps.c.orig	Wed Dec  8 08:55:59 2004
+++ src/ps.c	Wed Dec 29 22:57:48 2004
@@ -532,15 +532,16 @@
       section_len = line_len;
     } else if (iscomment(line,"%PDF-") && cmd_scan_pdf) {
       
-      /* PDF hack to set DELAYSAFER on interpreter invocation */
-      pdf_delaysafer_hack = 1;
-
       struct document *retval = NULL;
       FILE *tmpfile = (FILE*)NULL;
       char *filename_dsc;
       char cmd[512];
       char s[512];
       mode_t old_umask;
+
+      /* PDF hack to set DELAYSAFER on interpreter invocation */
+      pdf_delaysafer_hack = 1;
+
       filename_dsc=file_getTmpFilename(NULL,filename_raw);
       sprintf(cmd,cmd_scan_pdf,filename,filename_dsc);
       old_umask = umask(0077);
