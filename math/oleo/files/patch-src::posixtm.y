$FreeBSD$

--- src/posixtm.y.orig	Thu Jan  2 11:29:14 2003
+++ src/posixtm.y	Thu Jan  2 11:30:01 2003
@@ -85,6 +85,7 @@
 		   YYABORT;
 		 }
 	       }
+	   ;
 
 year : digitpair {
                    t.tm_year = $1;
