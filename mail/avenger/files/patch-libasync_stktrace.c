--- libasync/stktrace.c.orig	Sun Apr 10 03:54:35 2005
+++ libasync/stktrace.c	Fri May 20 06:52:45 2005
@@ -144,7 +144,7 @@
 #else /* !gcc 2 || !i386 */
 
 const char *
-__backtrace (const char *file)
+__backtrace (const char *file, int lim)
 {
   return file;
 }
