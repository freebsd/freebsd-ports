--- common/rw_log.c.orig	Tue Oct 28 02:28:43 2003
+++ common/rw_log.c	Tue Oct 28 02:30:14 2003
@@ -17,13 +17,10 @@
 #include "types.h"
 
 void
-log(va_alist)
-  va_dcl
+log(internal_log_levels level, int section, char *format, ...)
 {
   va_list             ap;
-  internal_log_levels level;
   FILE                *fp;
-  char                *format;
   char                *filename;
   char                *hostname;
   char                message[MAX_LINE];
@@ -31,13 +28,9 @@
   char                *section_name;
   int                 fd;
   int                 use_syslog;
-  int                 section;
   int                 syslog_level;
 
-  va_start(ap);
-  level   = (internal_log_levels) va_arg(ap, int);
-  section = (int) va_arg(ap, int);
-  format  = va_arg(ap, char*);
+  va_start(ap, format);
 
   /* verbosity sets the level at which we ignore log messages */
   if (level > get_verbosity())
@@ -142,4 +135,5 @@
 
     fclose(fp);
   }
+  va_end(ap);
 }
