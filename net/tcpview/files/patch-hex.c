--- hex.c.orig	1993-04-22 20:40:04 UTC
+++ hex.c
@@ -85,6 +85,7 @@ char *readline(buf)
   char *s;
 
   do {
+#define gets(a) gets_s(a,sizeof(a))
     if( gets(str) == NULL )
       return NULL;
     if( *str != '\t' && *str != ' ' && PrintFrames ) 
