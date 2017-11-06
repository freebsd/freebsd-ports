--- agrep.h.orig	1992-01-17 19:15:13 UTC
+++ agrep.h
@@ -1,10 +1,10 @@
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <math.h>
 #include <ctype.h>
 #include "re.h"
 
-extern unsigned char *strcpy(), *strncpy(), *strcat();
-extern int strlen();
 #define CHAR	unsigned char
 #define MAXPAT 128
 #define MAXPATT 256
@@ -52,3 +52,37 @@ extern int strlen();
 #define NNLINE    239   /* special symbol for newline in begin of pattern*/
                        /* matches '\n' and NNLINE */
 
+/* asearch.c */
+void asearch(CHAR old_D_pat[], int text, register unsigned D);
+
+/* asearch1.c */
+void asearch1(char old_D_pat[], int text, register unsigned D);
+
+/* bitap.c */
+void bitap(char old_D_pat[], char *Pattern, int fd, int M, int D);
+int fill_buf(int fd, unsigned char *buf, int record_size);
+
+/* checkfile.c */
+int check_file(char *fname);
+
+/* compat.c */
+void compat(void);
+
+/* main.c */
+void output (register CHAR *buffer, int i1, int i2, int j);
+void re1(int Text, int M, int D);
+void re(int Text, int M, int D);
+
+/* maskgen.c */
+int maskgen(unsigned char *Pattern, int D);
+
+/* mgrep.c */
+void prepf(int fp);
+void mgrep(int fp);
+
+/* preprocess.c */
+void preprocess(CHAR *D_pattern, CHAR *Pattern);
+
+/* sgrep.c */
+void sgrep(CHAR *pat, int m, int fd, int D);
+
