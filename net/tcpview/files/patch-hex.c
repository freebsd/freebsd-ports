--- hex.c.orig	1993-04-22 13:40:04.000000000 -0700
+++ hex.c	2017-10-06 07:25:01.182767000 -0700
@@ -85,6 +85,7 @@
   char *s;
 
   do {
+#define gets(a) fgets(a,sizeof(a),stdin)
     if( gets(str) == NULL )
       return NULL;
     if( *str != '\t' && *str != ' ' && PrintFrames ) 
