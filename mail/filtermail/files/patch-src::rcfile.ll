--- src/rcfile.ll.orig	Sun Jan 25 21:56:46 2004
+++ src/rcfile.ll	Fri Mar 19 23:18:03 2004
@@ -44,7 +44,7 @@
 
 extern "C"
 {
-#include "wordexp.h"
+#include "glob.h"
 }
 
 using namespace std;
@@ -125,7 +125,7 @@
 
 <INCL>[^ \t\n]+ {
      /* Include further rcfiles:  */
-     wordexp_t result;
+     glob_t result;
 
      if (include_stack_ptr >= MAX_INCLUDE_DEPTH)
      {
@@ -136,10 +136,10 @@
      
      try
      {
-        if (wordexp (yytext, &result, 0) == 0)
+        if (glob (yytext, 0, NULL, &result) == 0)
         {
-	   sub_file = result.we_wordv[0];
-           wordfree (&result);
+	   sub_file = result.gl_pathv[0];
+           globfree (&result);
         }
         else
         {
