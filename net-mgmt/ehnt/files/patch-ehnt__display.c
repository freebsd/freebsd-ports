
$FreeBSD$

--- ehnt_display.c.orig	Thu Oct  4 22:18:29 2001
+++ ehnt_display.c	Thu May 20 16:06:07 2004
@@ -246,7 +246,7 @@
 
 static char str[100];
 
-char * prettybytes(int bytes) {
+char * prettybytes(unsigned bytes) {
   
   if (bytes < 1024) sprintf(str,"%4d", bytes);
   else if (bytes < (1024*1024)) sprintf(str,"%4dK",(bytes/1024));
