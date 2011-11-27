--- preprocess.c.orig	1992-01-17 20:14:43.000000000 +0100
+++ preprocess.c	2011-11-27 12:47:32.000000000 +0100
@@ -14,6 +14,8 @@
 /* D_pattern contains transformed D_pattern                              */
    
 #include "agrep.h"
+
+extern int init(char *s, int table[32][32]);
   
 extern int SIMPLEPATTERN, WHOLELINE, REGEX, RE_ERR, DELIMITER, TAIL, WORDBOUND;
 extern int HEAD;
@@ -21,7 +23,7 @@
 extern int D_length;
 extern int table[WORD][WORD];
   
-preprocess(D_pattern, Pattern)   /* need two parameters  */
+void preprocess(D_pattern, Pattern)   /* need two parameters  */
 CHAR *D_pattern, *Pattern;
 {
   CHAR temp[Maxline], *r_pat, *old_pat;  /* r_pat for r.e. */
