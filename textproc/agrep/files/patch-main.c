--- main.c.orig	1992-04-14 20:41:24 UTC
+++ main.c
@@ -1,6 +1,14 @@
 /* Copyright (c) 1991 Sun Wu and Udi Manber.  All Rights Reserved. */
 #include "agrep.h"
 #include "checkfile.h"
+#include <unistd.h>
+#include <fcntl.h>
+
+int exponen(int m);
+void r_output (CHAR *buffer, int i, int end, int j);
+void file_out(char *fname);
+void usage(void);
+void checksg(CHAR *Pattern, int D);
 
 unsigned Mask[MAXSYM];
 unsigned Init1, NO_ERR_MASK, Init[MaxError];
@@ -33,7 +41,7 @@ int  NOFILENAME = 0,  /* Boolean flag, s
 extern int init();
 int table[WORD][WORD];
 
-initial_value()
+void initial_value()
 {
    int i; 
 
@@ -51,7 +59,7 @@ initial_value()
    for (i=0; i< MAXSYM; i++) Mask[i] = 0;
 }
 
-compute_next(M, Next, Next1)
+void compute_next(M, Next, Next1)
 int M; unsigned *Next, *Next1;
 {
   int i, j=0, n,  k, temp;
@@ -110,7 +118,7 @@ int M; unsigned *Next, *Next1;
   return;
 }
   
-exponen(m)
+int exponen(m)
 int m;
 { int i, ex;
   ex= 1;
@@ -118,7 +126,7 @@ int m;
   return(ex);
 }
 
-re1(Text, M, D)
+void re1(Text, M, D)
 int Text, M, D;
 {
   register unsigned i, c, r0, r1, r2, r3, CMask, Newline, Init0, r_NO_ERR; 
@@ -393,7 +401,7 @@ Nextchar1: i=i+1;
   return;
 } /* re1 */
 
-re(Text, M, D)
+void re(Text, M, D)
 int Text, M, D;
 {
   register unsigned i, c, r1, r2, r3, CMask, k, Newline, Init0, Init1, end; 
@@ -595,7 +603,7 @@ Nextchar1: i++;
 } /* re */
 
 
-r_output (buffer, i, end, j) 
+void r_output (buffer, i, end, j) 
 int i, end, j; 
 CHAR *buffer;
 {
@@ -612,7 +620,7 @@ int bp;
       while (bp <= i ) putchar(buffer[bp++]);
 }
 
-main(argc, argv)
+int main(argc, argv)
 int argc; char *argv[];
 {
   int N, M, D=0, fp, fd, i, j; 
@@ -751,7 +759,7 @@ int argc; char *argv[];
   }
   if (!(PAT_FILE) && Pattern[0] == '\0') { /* Pattern not set with -e option */
     if (argc == 0) usage();
-    strcpy(Pattern, *argv); 
+    strncpy(Pattern, *argv, sizeof(Pattern)); 
     argc--;
     argv++;
   }
@@ -897,7 +905,7 @@ CONT:
 } /* end of main() */
 
 	   
-file_out(fname)
+void file_out(fname)
 char *fname;
 {
 int num_read;
@@ -921,7 +929,7 @@ CHAR buf[4097];
 }
 
 
-usage()
+void usage()
 {
     	fprintf(stderr, "usage: %s [-#cdehiklnpstvwxBDGIS] [-f patternfile] pattern [files]\n", Progname); 
  	printf("\n");	
@@ -942,7 +950,7 @@ usage()
     	exit(2);
 }
 
-checksg(Pattern, D) 
+void checksg(Pattern, D) 
 CHAR *Pattern; int D;
 {                          
   char c;
@@ -999,7 +1007,8 @@ CHAR *Pattern; int D;
   return;
 }
 
-output (buffer, i1, i2, j)  
+void output (register CHAR *buffer, int i1, int i2, int j);
+void output (buffer, i1, i2, j)  
 register CHAR *buffer; int i1, i2, j;
 {
 register CHAR *bp, *outend;
