--- wxbasic.y.orig	Sun Dec 15 13:17:34 2002
+++ wxbasic.y	Sun Dec 15 13:21:01 2002
@@ -378,7 +378,7 @@
         {   $$ = wOpNode( W_OP_CLOSE, NULL, NULL ); }
 
     | W_TOKEN_CONST constList sep
-        { $$ = $2 }
+        { $$ = $2; }
 
     | W_TOKEN_COMMON
         {   if (wCurrentScope != NULL) {
@@ -397,7 +397,7 @@
             $$ = wOpNode( W_OP_CONTINUE, NULL, NULL ); }
 
     | W_TOKEN_DELETE expr sep
-        { $$ = wOpNode( W_OP_DELETE, $2, NULL ) }
+        { $$ = wOpNode( W_OP_DELETE, $2, NULL ); }
 
     /* same as Dim Common */
     | W_TOKEN_DIM W_TOKEN_COMMON
@@ -486,7 +486,7 @@
                 wSymbolNode( W_OP_NOOP, $5, NULL, NULL ), $9 ); }
 
     | W_TOKEN_FOR W_TOKEN_EACH W_TOKEN_VARIABLE_NAME W_TOKEN_IN error
-        {   wExpected("an Array") };
+        {   wExpected("an Array"); };
                                
 
     | W_TOKEN_FOR W_TOKEN_EACH W_TOKEN_UNDEFINED W_TOKEN_IN W_TOKEN_ARRAY_NAME
@@ -498,16 +498,16 @@
                 wSymbolNode( W_OP_NOOP, $5, NULL, NULL ), $8 ); }
 
     | W_TOKEN_FOR W_TOKEN_EACH W_TOKEN_UNDEFINED W_TOKEN_IN error
-        {   wExpected("an Array") };
+        {   wExpected("an Array"); };
 
     | W_TOKEN_FOR W_TOKEN_EACH W_TOKEN_VARIABLE_NAME error
-        {   wExpected("In") };
+        {   wExpected("In"); };
 
     | W_TOKEN_FOR W_TOKEN_EACH W_TOKEN_UNDEFINED error
-        {   wExpected("In") };
+        {   wExpected("In"); };
 
     | W_TOKEN_FOR W_TOKEN_EACH error
-        {   wExpected("a variable") };
+        {   wExpected("a variable"); };
 
     /* For <var> = <expr> To <expr> [step <expr>] ... next */
     | W_TOKEN_FOR W_TOKEN_VARIABLE_NAME 
@@ -1328,7 +1328,7 @@
 
 printList:
       ';' printList
-        { $$ = $2 }
+        { $$ = $2; }
 
     | ',' printList
         { $$ = wIntNode( W_OP_PRINT_VALUE, W_PRINT_TAB, NULL, $2 ); }
@@ -1519,7 +1519,7 @@
         {   wIncrStack( wArgCountStack, 1 );
             if ($1->stackPos != wPeekStack(wArgCountStack) ) {
                 wFatal( W_SYNTAX, "Variable %s does not match declaration", $1->name);
-            } };
+            } }
 
     | W_TOKEN_VARIABLE_NAME ',' optSep 
         {   wIncrStack( wArgCountStack, 1 );
@@ -1558,7 +1558,7 @@
     | '.' '.' '.' ')'
         {   if (wCurrentScope->optArgs != W_MAX_OPT_ARGS) {
                 wFatal( W_SYNTAX, "... does not match declaration" );
-            } };
+            } }
     | error
         {   wFatal( W_SYNTAX, "Parm list does not match declaration" ); }
 
@@ -1617,8 +1617,8 @@
 
 fileHandle
     : '#' expr
-        {   $$ = $2 }
+        {   $$ = $2; }
     | expr
-        {   $$ = $1 }
+        {   $$ = $1; }
     ;
 
