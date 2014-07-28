--- /tmp/Eval/source/eval.h	Tue Apr 13 21:04:44 1993
+++ eval.h	Wed Mar 16 04:26:57 1994
@@ -55,6 +55,8 @@
 #define    MAXINPUT    160
 #define    NUMFUNCS    30
 #define    MAXFLEN     6
+#define    MAXALEN     3
+#define    MAXDLEN     80
 #define    SCRWIDTH    80
 #define    MAXARGS     10
 #define    EOS          '\0'
@@ -115,6 +117,12 @@
                char    type;
                int     code;
                } TOKEN, *TOKENPTR;
+typedef struct {
+               int     id;
+               char    name[MAXFLEN+1];
+               char    argspec[MAXALEN+1];
+               char    desc[MAXDLEN+1];
+               } FUNC, *FUNCPTR;
 
 /* Function definitions */
 
@@ -131,6 +139,8 @@
 char   *func_name       (int);
 int     func_nargs      (int);
 int     print_funclist  (FILE *s,char *input,int d);
+
+extern FUNC    flist[];
 
 /* ----- PARSE.C functions -------------------------------------------- */
 
