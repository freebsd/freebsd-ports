--- preprocess.c.orig	1992-01-17 19:14:43 UTC
+++ preprocess.c
@@ -14,6 +14,8 @@
 /* D_pattern contains transformed D_pattern                              */
    
 #include "agrep.h"
+
+extern int init(char *s, int table[32][32]);
   
 extern int SIMPLEPATTERN, WHOLELINE, REGEX, RE_ERR, DELIMITER, TAIL, WORDBOUND;
 extern int HEAD;
@@ -21,7 +23,7 @@ extern CHAR Progname[];
 extern int D_length;
 extern int table[WORD][WORD];
   
-preprocess(D_pattern, Pattern)   /* need two parameters  */
+void preprocess(D_pattern, Pattern)   /* need two parameters  */
 CHAR *D_pattern, *Pattern;
 {
   CHAR temp[Maxline], *r_pat, *old_pat;  /* r_pat for r.e. */
