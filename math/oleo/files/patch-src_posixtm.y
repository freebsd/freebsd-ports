--- src/posixtm.y.orig	2000-07-22 06:13:16 UTC
+++ src/posixtm.y
@@ -85,6 +85,7 @@ date :
 		   YYABORT;
 		 }
 	       }
+	   ;
 
 year : digitpair {
                    t.tm_year = $1;
