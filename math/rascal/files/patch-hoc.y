--- hoc.y.orig	Thu Jun 20 10:22:54 2002
+++ hoc.y	Thu Jun 20 10:35:33 2002
@@ -36,6 +36,10 @@
 #include <math.h>
 #include <stdlib.h>
 #include <string.h>
+#include <stdio.h>
+extern "C" {
+#include <getopt.h>
+}
 int precis=8;
 
 void * set_string_input(char *);
@@ -197,17 +201,17 @@
 	;
 PARSERexpr:
 	  PARSERexpr PARSERwhite { $$ = $1; }	
-	| PARSERfunction	{ $$ = new value($1) }
-	| PARSERfunction2	{ $$ = new value($1) }
-	| PARSERat PARSERprocedure	{ $$ = new value($2) }
-	| PARSERuserfunction	{ $$ = new value($1) }
-	| PARSERat PARSERvariable	{ $$ = new value($2) }
+	| PARSERfunction	{ $$ = new value($1); }
+	| PARSERfunction2	{ $$ = new value($1); }
+	| PARSERat PARSERprocedure	{ $$ = new value($2); }
+	| PARSERuserfunction	{ $$ = new value($1); }
+	| PARSERat PARSERvariable	{ $$ = new value($2); }
 	| PARSERlbracket PARSERexprlist PARSERrbracket { $$=new value(bracket(cell(($2)->asMATRIX(),1),cell(($2)->asMATRIX(),2))); delete $2; }
         | PARSERwhite PARSERexpr %prec PARSERbecomes	{ $$ = $2; }
 	| PARSERnumber			{ $$ = $1; }
 	| PARSERvariable		{ $$ = new value($1->var); }
-	| PARSERvariable PARSERplusplus { $1->var=$1->var+1; $$ = new value($1->var) }
-	| PARSERvariable PARSERminusminus { $1->var=$1->var-1; $$ = new value($1->var) }
+	| PARSERvariable PARSERplusplus { $1->var=$1->var+1; $$ = new value($1->var); }
+	| PARSERvariable PARSERminusminus { $1->var=$1->var-1; $$ = new value($1->var); }
         | PARSERvariable PARSERbecomes PARSERexpr { $$ = $3; $1->var=*($3);}
 	| PARSERprocedure 		{ $$=new value( (*($1->ivalue.procptr))() ); }
 	| PARSERexpr PARSERlbracket PARSERmatrix PARSERrbracket	
