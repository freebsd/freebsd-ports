--- Makefile.PL.orig	Mon Nov 29 21:27:09 2004
+++ Makefile.PL	Thu Oct 20 11:21:23 2005
@@ -18,12 +18,14 @@ $xmllibxml_version = 1.54;
 		'XML::DTDParser' => '2.00',
 	       );
 
+$PARSER = "XML::LibXML";  # no user interaction, sir!
+
 if ($PARSER) {
-  $PARSER=~m!PARSER=!;
-  $XML = uc($');
-  unless ($XML eq "XML::PARSER" || $XML eq "XML::LIBXML") {
+#  $PARSER=~m!PARSER=!;
+  $XML = $PARSER;
+  unless ($XML eq "XML::PARSER" || $XML eq "XML::LibXML") {
     print STDERR "Unknown parser. Using default: XML::LibXML\n";
-    $XML = "XML::LIBXML";
+    $XML = "XML::LibXML";
   }
 } else {
   print "\n";
