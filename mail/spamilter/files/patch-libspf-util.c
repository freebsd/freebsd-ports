--- libspf/util.c.orig	Thu Apr 29 15:47:30 2004
+++ libspf/util.c	Sat Nov 27 08:32:05 2004
@@ -61,7 +61,7 @@
 void _printf_dbg(u_int8_t level, const char *function, const char *format,...)
 {
   char     _dbg_output[MAX_DEBUG_LEN];
-  va_list  argptr   = NULL;
+  va_list  argptr;
 
 #ifdef _SPF_DEBUG_LOGFILE
   FILE     *fp      = NULL;
