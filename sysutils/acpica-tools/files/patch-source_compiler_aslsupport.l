--- source/compiler/aslsupport.l.orig	2017-09-29 15:34:59 UTC
+++ source/compiler/aslsupport.l
@@ -525,7 +525,7 @@ static void
 count (
     int                 Type)
 {
-    int                 i;
+    int                 c, i;
 
 
     switch (Type)
@@ -547,10 +547,12 @@ count (
         break;
     }
 
-    for (i = 0; (yytext[i] != 0) && (yytext[i] != EOF); i++)
+    i = 0;
+    while ((c = yytext[i]) != 0 && c != EOF)
     {
-        AslInsertLineBuffer (yytext[i]);
+        AslInsertLineBuffer (c);
         *Gbl_LineBufPtr = 0;
+        i++;
     }
 }
 
