--- mgrep.c.orig	1992-04-10 22:12:27 UTC
+++ mgrep.c
@@ -1,7 +1,10 @@
 /* Copyright (c) 1991 Sun Wu and Udi Manber.  All Rights Reserved. */
 /* multipattern matcher */
 #include <stdio.h>
+#include <stdlib.h>
 #include <ctype.h>
+#include <string.h>
+#include <unistd.h>
 #define MAXPAT  256
 #define MAXLINE 1024
 #define MAXSYM  256
@@ -14,11 +17,16 @@
 #define W_DELIM	   128
 #define L_DELIM    10 
 
-extern COUNT, FNAME, SILENT, FILENAMEONLY, num_of_matched;
-extern INVERSE;
-extern WORDBOUND, WHOLELINE, NOUPPER;
+void countline(unsigned char *text, int len);
+void monkey1( register unsigned char *text, int start, int end );
+void m_short( register unsigned char *text, int start, int end );
+void f_prep(int pat_index, unsigned char *Pattern);
+
+extern int COUNT, FNAME, SILENT, FILENAMEONLY, num_of_matched;
+extern int INVERSE;
+extern int WORDBOUND, WHOLELINE, NOUPPER;
 extern unsigned char  CurrentFileName[], Progname[]; 
-extern total_line;
+extern int total_line;
 
 int LONG  = 0;
 int SHORT = 0;
@@ -37,7 +45,7 @@ unsigned char *patt[max_num];
 unsigned char pat_len[max_num];
 
 
-prepf(fp)
+void prepf(fp)
 int fp;
 {
     int length=0, i, p=1, pdx=0, num_pat;
@@ -85,7 +93,7 @@ int fp;
 	if(p!=0 && p < p_size) p_size = p;
     }
     if(p_size == 0) {
-	fprintf(stderr, "%s: the pattern file is empty\n");
+	fprintf(stderr, "%s: the pattern file is empty\n", Progname);
 	exit(2);
     }
     if(length > 400 && p_size > 2) LONG = 1;
@@ -98,7 +106,7 @@ int fp;
 }
 
 
-mgrep(fd)
+void mgrep(fd)
 int fd;
 { 
     register char r_newline = '\n';
@@ -136,7 +144,7 @@ int fd;
     return;
 } /* end mgrep */
 
-countline(text, len)
+void countline(text, len)
 unsigned char *text; int len;
 {
 int i;
@@ -144,7 +152,7 @@ int i;
 }
 
 
-monkey1( text, start, end  ) 
+void monkey1( text, start, end  ) 
 int start, end; register unsigned char *text;
 {
 register unsigned char *textend;
@@ -232,7 +240,7 @@ while (text <= textend) {
   if(INVERSE && !COUNT) while(lastout <= textend) putchar(*lastout++);
 }
 
-m_short( text, start, end  ) 
+void m_short( text, start, end  ) 
 int start, end; register unsigned char *text;
 {
 register unsigned char *textend;
@@ -292,7 +300,7 @@ while (++text <= textend) {
   if(INVERSE && !COUNT) while(lastout <= textend) putchar(*lastout++);
 }
 
-f_prep(pat_index, Pattern)
+void f_prep(pat_index, Pattern)
 unsigned char *Pattern ; int pat_index;
 {
 int i, j, m;
