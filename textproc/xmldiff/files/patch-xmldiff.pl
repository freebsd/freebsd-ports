--- xmldiff.pl.orig	Sun Oct  9 11:59:04 2005
+++ xmldiff.pl	Sun Oct  9 11:59:37 2005
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
