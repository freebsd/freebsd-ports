--- filter/subtitler/frame_list.c.orig	Thu Feb 26 17:30:59 2004
+++ filter/subtitler/frame_list.c	Thu Feb 26 17:36:19 2004
@@ -33,8 +33,8 @@
 
 char *strsave(char *s) /*save char array s somewhere*/
 {
-char *p, *malloc();
-if(p = malloc( strlen(s) +  1) ) strcpy(p, s);
+char *p;
+if(p = (char *)malloc( strlen(s) +  1) ) strcpy(p, s);
 return(p);
 }
 
