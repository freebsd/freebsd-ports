--- /tmp/Eval/source/funcs.c	Tue Apr 13 21:04:40 1993
+++ funcs.c	Wed Mar 16 04:31:35 1994
@@ -52,16 +52,6 @@
 
 #include   "eval.h"
 
-#define MAXALEN     3
-#define MAXDLEN     80
-
-typedef struct {
-               int     id;
-               char    name[MAXFLEN+1];
-               char    argspec[MAXALEN+1];
-               char    desc[MAXDLEN+1];
-               } FUNC, *FUNCPTR;
-
 #define    ABSVAL      1
 #define    ACOS        2
 #define    ACOSH       3
@@ -93,7 +83,7 @@
 #define    TAN         29
 #define    TANH        30
 
-static FUNC    flist[NUMFUNCS] =
+FUNC    flist[NUMFUNCS] =
 {
 {ABSVAL,"abs",    "x",  "absolute value"                              },
 {ACOS,  "acos",   "x",  "arccosine, return value in radians"          },
