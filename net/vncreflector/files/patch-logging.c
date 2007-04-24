
$FreeBSD$

--- logging.c
+++ logging.c
@@ -10,7 +10,7 @@
  * This software was authored by Constantin Kaplinsky <const@ce.cctpu.edu.ru>
  * and sponsored by HorizonLive.com, Inc.
  *
- * $Id: logging.c,v 1.1 2007/04/24 05:32:17 root Exp $
+ * $Id: logging.c,v 1.5 2003/04/21 17:20:35 const Exp $
  * Logging implementation
  */
 
@@ -138,8 +138,6 @@
   char time_buf[32];
   char level_char = ' ';
 
-  va_start(arg_list, format);
-
   if ( (log_fp != NULL && level <= log_file_level) ||
        level <= log_stderr_level ) {
     now = time(NULL);
@@ -150,18 +148,21 @@
 
     if (level <= log_file_level) {
       fprintf(log_fp, "%s %c ", time_buf, (int)level_char);
+      va_start(arg_list, format);
       vfprintf(log_fp, format, arg_list);
+      va_end(arg_list);
       fprintf(log_fp, "\n");
       fflush(log_fp);
     }
     if (level <= log_stderr_level) {
       fprintf(stderr, "%s %c ", time_buf, (int)level_char);
+      va_start(arg_list, format);
       vfprintf(stderr, format, arg_list);
+      va_end(arg_list);
       fprintf(stderr, "\n");
       fflush(stderr);
     }
   }
 
-  va_end(arg_list);
 }
 
