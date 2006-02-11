--- xmldiff.pl.orig	Sat Feb 11 08:32:29 2006
+++ xmldiff.pl	Sat Feb 11 08:32:38 2006
@@ -7,12 +7,12 @@
 # 
 
 #
-# xmldiff: xmldiff program - uses xmlpp
+# xmldiff: xmldiff program - uses xmlprpr
 #
 
 #Change this if xmlpp is not in your current path
 #for example: $XMLPP = "./xmlpp";
-$XMLPP = "xmlpp";
+$XMLPP = "xmlprpr";
 
 # older versions of less don't support -R, consider -r instead
 my $pagerCmd = ' | less -R ';
