--- bc/bc.y.orig	Sun Oct 24 10:07:01 2004
+++ bc/bc.y	Sun Oct 24 10:07:20 2004
@@ -424,7 +424,6 @@
 			      generate (genstr);
 			      $$ = 0;
 			    }
-			;
 			| expression AND 
 			    {
 			      warn("&& operator");
