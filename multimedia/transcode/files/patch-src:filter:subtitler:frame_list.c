--- filter/subtitler/frame_list.c.orig	Thu May 23 10:53:06 2002
+++ filter/subtitler/frame_list.c	Thu May 23 10:53:34 2002
@@ -33,8 +33,8 @@
 
 char *strsave(char *s) /*save char array s somewhere*/
 {
-char *p, *malloc();
-if(p = malloc( strlen(s) +  1) ) strcpy(p, s);
+char *p;
+if(p = (char *)malloc( strlen(s) +  1) ) strcpy(p, s);
 return(p);
 }
 
