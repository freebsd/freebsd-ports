--- server/notify.c.orig	Tue Oct 28 02:30:38 2003
+++ server/notify.c	Tue Oct 28 02:31:26 2003
@@ -75,18 +75,13 @@
 
 /* log notify information */
 int
-log_entry(va_alist)
-  va_dcl
+log_entry(char *filename, char *format, ...)
 {
   va_list   ap;
   FILE      *fp;
-  char      *format;
-  char      *filename;
   char      *hostname;
 
-  va_start(ap);
-  filename  = va_arg (ap, char*);
-  format    = va_arg(ap, char*);
+  va_start(ap, format);
 
   /* lock the file */
   fp = get_file_lock(filename, "a", 60);
@@ -103,6 +98,7 @@
   fprintf(fp, " [%-15s] PID: %-8d", hostname, (int) getpid());
   vfprintf(fp, format, ap);
   fprintf(fp, "\n");
+  va_end(ap);
 
   release_file_lock(filename, fp);
 
