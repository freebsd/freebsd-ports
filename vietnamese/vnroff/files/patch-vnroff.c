--- vnroff.c.orig	Sat May 20 11:32:08 2000
+++ vnroff.c	Sat May 20 11:52:54 2000
@@ -19,7 +19,7 @@
  * #define Dau_Mu          '^'                                          *
  * #define Dau_Trang       '('                                          *
  * #define Dau_Rau         '+'                                          *
- * #define Escape_Symbol   '#'                                          *
+ * #define Escape_Symbol   '\\'                                         *
  *                                                                      *
  * Change them to any symbol you are comfortable with.                  *
  *                                                                      *
@@ -29,8 +29,8 @@
  * 2 diacritical marks: vowel followed by Dau_Mu, Dau_Trang, Dau_Rau    *
  *                     then other symbols, i.e: a^' o+~ a(` ...         *
  *                                                                      *
- * DD and dd: self-explanatory, you have to type DD or dd, Dd or dD     *
- *            will not work.  You can change the code to ignore this.   *
+ * DD and dd: self-explanatory, the resulting case is the same as the   *
+ * first character of [Dd][Dd].                                         *
  *                                                                      *
  * The Escape_Symbol is provided to avoid the confusion between the     *
  * diacritical marks and end-of-sentence symbols (. ; ? ! ...)          *
@@ -54,7 +54,7 @@
 #define Dau_Mu          '^'
 #define Dau_Trang       '('
 #define Dau_Rau         '+'
-#define Escape_Symbol   '#'
+#define Escape_Symbol   '\\'
 
 #define NON     0          /* ^ as in a^ */
 #define RAU     1          /* + as in u+, o+ */
@@ -308,7 +308,7 @@
    int ch,nextch,loai;
 
    if (argc < 2) {
-      printf("Usage: vpp filename\n");
+      printf("Usage: vnroff filename\n");
       exit(0);
    }
    if ((infile = fopen(argv[1],"r")) == NULL) {
@@ -344,9 +344,9 @@
 	 else
 	    putchar(ch);
       }
-      else if (ch == 'D' || ch == 'd') {       /* take care DD, dd */
+      else if (toupper(ch) == 'D') {       /* take care DD, dd */
 	 putchar(ch);
-	 if (nextchar() == ch) {
+	 if (toupper(nextchar()) == toupper(ch)) {
 	    getc(infile);
 	    if (ch == 'd')  
                Move(0.30,0.35,'-'); 
