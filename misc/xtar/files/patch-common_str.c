--- ./common/str.c.orig	Tue May  9 01:06:46 1995
+++ ./common/str.c	Mon Nov 18 01:23:20 2002
@@ -282,8 +282,6 @@
   ---------------------------------------------------------------------------*/
 char *str_error(int errnum)
 {
-        extern int sys_nerr;
-        extern char *sys_errlist[];
         static char ebuf[40];           /* 64-bit number + slop */
 
         if ((unsigned int)errnum < sys_nerr)
