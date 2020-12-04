--- src/app_main.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/app_main.cpp
@@ -143,7 +143,7 @@ class GCats : public GFanApplication (public)
 	{
 	  log1 fprintf(Stderr,"Computing Groebner Basis...\n");
 	  buchberger(&g,StandardGradedLexicographicTermOrder());
-	  log2 AsciiPrinter(Stderr).printPolynomialSet(g);
+	  gfan_log2 AsciiPrinter(Stderr).printPolynomialSet(g);
 	}
       log1 fprintf(Stderr,"A reduced Groebner basis has been computed\n");
     }
