--- source/compiler/aslsupport.l.orig	2017-11-10 16:05:28 UTC
+++ source/compiler/aslsupport.l
@@ -525,7 +525,7 @@ static void
 count (
     int                 Type)
 {
-    int                 i;
+    char                *p;
 
 
     switch (Type)
@@ -547,9 +547,9 @@ count (
         break;
     }
 
-    for (i = 0; (yytext[i] != 0) && (yytext[i] != EOF); i++)
+    for (p = yytext; *p != '\0'; p++)
     {
-        AslInsertLineBuffer (yytext[i]);
+        AslInsertLineBuffer (*p);
         *Gbl_LineBufPtr = 0;
     }
 }
