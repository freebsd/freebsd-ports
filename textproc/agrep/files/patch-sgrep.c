--- sgrep.c.orig	1992-04-10 22:12:02 UTC
+++ sgrep.c
@@ -1,6 +1,9 @@
 /* Copyright (c) 1991 Sun Wu and Udi Manber.  All Rights Reserved. */
 #include <stdio.h>
+#include <stdlib.h>
 #include <ctype.h>
+#include <string.h>
+#include <unistd.h>
 #define MAXSYM  256
 #define MAXMEMBER 8192
 #define	CHARTYPE	unsigned char
@@ -18,10 +21,10 @@
 #define LONG_APPX  24
 #define W_DELIM    128
 
-extern COUNT, FNAME, SILENT, FILENAMEONLY, num_of_matched;
-extern DNA ;  /* DNA flag is set in checksg when pattern is DNA pattern and
+extern int COUNT, FNAME, SILENT, FILENAMEONLY, num_of_matched;
+extern int DNA ;  /* DNA flag is set in checksg when pattern is DNA pattern and
 		 p_size > 16  */
-extern WORDBOUND, WHOLELINE, NOUPPER;
+extern int WORDBOUND, WHOLELINE, NOUPPER;
 extern unsigned char CurrentFileName[],  Progname[]; 
 extern unsigned Mask[];
 extern unsigned endposition;
@@ -30,6 +33,21 @@ unsigned char BSize;                /* l
 unsigned char char_map[MAXSYM];
 	
 
+void bm(CHARTYPE *pat, int m, CHARTYPE *text, CHARTYPE *textend);
+void initmask(CHARTYPE *pattern, unsigned *Mask, register int m, register int D, unsigned *endposition);
+void prep(CHARTYPE *Pattern, register int M, register int D);
+void agrep( register CHARTYPE *pat, int M, register CHARTYPE *text, register CHARTYPE *textend, int D );
+void s_output (CHARTYPE *text, int *i);
+void prep_bm(unsigned char *Pattern, register int m);
+void a_monkey( register unsigned char *pat, register int m, register unsigned char *text, register unsigned char *textend, register int D );
+void am_preprocess(CHARTYPE *Pattern);
+int verify(register int m, register int n, register int D, CHARTYPE *pat, CHARTYPE *text);
+void monkey( register unsigned char *pat, register int m, register unsigned char *text, register unsigned char *textend );
+void monkey4( register unsigned char *pat, int m, register unsigned char *text, register unsigned char *textend, int D  );
+void m_preprocess(CHARTYPE *Pattern);
+void prep4(char *Pattern, int m);
+int blog(int base, int m );
+
 /* data area */
 int shift_1;
 CHARTYPE SHIFT[MAXSYM];
@@ -39,7 +57,7 @@ unsigned Hashmask;
 char MEMBER_1[MAXMEMBER_1];
 CHARTYPE TR[MAXSYM];
 
-char_tr(pat, m)
+void char_tr(pat, m)
 	unsigned char *pat;
 	int *m;
 {
@@ -64,7 +82,7 @@ unsigned char temp[MAXPATT];
 	}
 }
 
-sgrep(pat, m, fd, D)
+void sgrep(pat, m, fd, D)
 CHARTYPE *pat;  int fd, m, D;
 { 
     CHARTYPE text[BLOCKSIZE+2*MAXLINE+MAXPATT]; /* input text stream */
@@ -126,7 +144,7 @@ CHARTYPE *pat;  int fd, m, D;
 /* SUN: bm assumes that the content of text[n]...text[n+m-1] is 
 pat[m-1] such that the skip loop is guaranteed to terminated */
 
-bm(pat, m, text, textend)
+void bm(pat, m, text, textend)
 	CHARTYPE *text, *textend, *pat;  int m;
 {
 register int shift;
@@ -179,7 +197,7 @@ return;
 /* initmask() initializes the mask table for the pattern                    */ 
 /* endposition is a mask for the endposition of the pattern                 */
 /* endposition will contain k mask bits if the pattern contains k fragments */
-initmask(pattern, Mask, m, D, endposition)
+void initmask(pattern, Mask, m, D, endposition)
 CHARTYPE *pattern; unsigned *Mask; register int m, D; unsigned *endposition;
 {
   register unsigned Bit1, c;
@@ -202,7 +220,7 @@ CHARTYPE *pattern; unsigned *Mask; regis
   }
 }
 
-prep(Pattern, M, D)             /* preprocessing for partitioning_bm */
+void prep(Pattern, M, D)             /* preprocessing for partitioning_bm */
 	CHARTYPE *Pattern;  /* can be fine-tuned to choose a better partition */
 	register int M, D;
 {
@@ -250,7 +268,7 @@ unsigned hash, b_size = 3;
 }
 
 
-agrep( pat, M, text, textend, D ) 
+void agrep( pat, M, text, textend, D ) 
 int M, D ; register CHARTYPE *text, *textend, *pat;
 {
   register int i;
@@ -357,7 +375,7 @@ int M, D ; register CHARTYPE *text, *tex
   return;
 }
 
-s_output (text, i) 
+void s_output (text, i) 
 int *i; CHARTYPE *text;
 {
 int kk, bp;
@@ -375,9 +393,9 @@ int kk, bp;
 }
 
 
-prep_bm(Pattern, m)      
+void prep_bm(Pattern, m)      
 	unsigned char *Pattern;
-	register m;
+	register int m;
 {
 int i, j;
 unsigned hash;
@@ -404,7 +422,7 @@ unsigned char lastc;
 
 /* a_monkey() the approximate monkey move */
 
-a_monkey( pat, m, text, textend, D ) 
+void a_monkey( pat, m, text, textend, D ) 
 register int m, D ; register CHARTYPE *text, *textend, *pat;
 {
 register CHARTYPE *oldtext;
@@ -451,7 +469,7 @@ register int  m1 = m-1-D, j, pos; 
 
 CHARTYPE SHIFT_2[MAX_SHIFT_2];
 
-monkey( pat, m, text, textend  ) 
+void monkey( pat, m, text, textend  ) 
 register int m  ; register CHARTYPE *text, *textend, *pat;
 {
 register unsigned hash, i; 
@@ -494,7 +512,7 @@ r_newline = '\n';
   }
 }
  
-am_preprocess(Pattern)
+void am_preprocess(Pattern)
 CHARTYPE *Pattern;
 {
 int i, j, m;
@@ -511,7 +529,7 @@ unsigned hash;
 }
 
 
-verify(m, n, D, pat, text)
+int verify(m, n, D, pat, text)
 register int m, n, D;
 CHARTYPE *pat, *text;
 {   
@@ -566,7 +584,7 @@ CHARTYPE *pat, *text;
 
 /* preprocessing for monkey()   */
 
-m_preprocess(Pattern)
+void m_preprocess(Pattern)
 CHARTYPE *Pattern;
 {
 int i, j, m;
@@ -595,7 +613,7 @@ unsigned hash;
 
 char *MEMBER_D;
 
-monkey4( pat, m, text, textend, D  ) 
+void monkey4( pat, m, text, textend, D  ) 
 register int m, D ; register unsigned char *text, *pat, *textend;
 {
 register unsigned char *oldtext;
@@ -639,7 +657,7 @@ register int m1=m-1-D, j, pos; 
   }
 }
  
-prep4(Pattern, m)
+void prep4(Pattern, m)
 char *Pattern; int m;
 {
 int i, j, k;
@@ -672,7 +690,7 @@ char_map['n'] = char_map['n'] = 5;
         }
 }
 
-blog(base, m )
+int blog(base, m )
 int base, m;
 {
 int i, exp;
