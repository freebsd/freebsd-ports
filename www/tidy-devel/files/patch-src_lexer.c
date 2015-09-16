--- src/lexer.c.orig	2008-03-22 21:06:55 UTC
+++ src/lexer.c
@@ -3467,16 +3467,17 @@ static tmbstr ParseValue( TidyDocImpl* d
         /* and prompts attributes unless --literal-attributes is set to yes      */
         /* #994841 - Whitespace is removed from value attributes                 */
 
-        if (munge &&
+	/* Issue #217 from tidy-html5 - Also only if/while (len > 0) - MUST NEVER GO NEGATIVE! */
+        if ((len > 0) && munge &&
             TY_(tmbstrcasecmp)(name, "alt") &&
             TY_(tmbstrcasecmp)(name, "title") &&
             TY_(tmbstrcasecmp)(name, "value") &&
             TY_(tmbstrcasecmp)(name, "prompt"))
         {
-            while (TY_(IsWhite)(lexer->lexbuf[start+len-1]))
+            while (TY_(IsWhite)(lexer->lexbuf[start+len-1]) && (len > 0))
                 --len;
 
-            while (TY_(IsWhite)(lexer->lexbuf[start]) && start < len)
+            while (TY_(IsWhite)(lexer->lexbuf[start]) && (start < len) && (len > 0))
             {
                 ++start;
                 --len;
