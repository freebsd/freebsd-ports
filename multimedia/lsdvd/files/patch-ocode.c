--- ocode.c.orig	Sat Nov 25 19:46:18 2006
+++ ocode.c	Sat Nov 25 19:45:59 2006
@@ -114,8 +114,7 @@
         INDENT;
         if (_lvl) {
 		printf(syntax->array_inner, name);
-		printf(_lvl_return[_lvl]);
-		//sprintf(_lvl_return[_lvl], syntax->return_array_inner, name);
+		_lvl_return[_lvl] = syntax->return_array_inner;
         } else {
                 printf(syntax->array_outer, name);
                 _lvl_return[_lvl] = syntax->return_array_outer;
