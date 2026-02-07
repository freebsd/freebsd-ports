--- logging.c.orig	2003-04-21 17:20:35 UTC
+++ logging.c
@@ -138,8 +138,6 @@ void log_write(int level, char *format, ...)
   char time_buf[32];
   char level_char = ' ';
 
-  va_start(arg_list, format);
-
   if ( (log_fp != NULL && level <= log_file_level) ||
        level <= log_stderr_level ) {
     now = time(NULL);
@@ -150,18 +148,21 @@ void log_write(int level, char *format, ...)
 
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
 
