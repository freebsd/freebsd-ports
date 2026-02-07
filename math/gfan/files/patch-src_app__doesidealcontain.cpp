--- src/app_doesidealcontain.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/app_doesidealcontain.cpp
@@ -52,9 +52,9 @@ class DoesIdealContainApplication : public GFanApplica
     	for(PolynomialSet::const_iterator i=b.begin();i!=b.end();i++)
     	{
     		Polynomial remainder=division(multiplier* *i,a,LexicographicTermOrder());
-	log2 AsciiPrinter(Stderr).printString("Remainder: ");
-	log2 AsciiPrinter(Stderr).printPolynomial(remainder);
-	log2 AsciiPrinter(Stderr).printNewLine();
+	gfan_log2 AsciiPrinter(Stderr).printString("Remainder: ");
+	gfan_log2 AsciiPrinter(Stderr).printPolynomial(remainder);
+	gfan_log2 AsciiPrinter(Stderr).printNewLine();
 	if(!remainder.isZero())
 	  {
 	    log1 AsciiPrinter(Stderr).printString("Polynomial not in ideal: ");
