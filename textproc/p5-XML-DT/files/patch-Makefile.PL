--- Makefile.PL.orig	Sun Oct 12 22:45:13 2003
+++ Makefile.PL	Mon Oct 13 20:53:10 2003
@@ -9,26 +9,26 @@
 		'LWP::Simple' => '1.35',
 	       );
 
-print "\n";
-print " NOTE: Next versions will, possibly, deprecate XML::Parser backend.\n";
-print "       At the moment, XML::LibXML is quicker than XML::Parser and\n";
-print "       supports HTML parsing\n\n";
-
-print "I need a XML Back-end (XML::Parser >= $xmlparser_version or XML::LibXML >= $xmllibxml_version\n";
-do {
-  print "Sorry, I didn't understand the answer.\n" if ($answer);
-  print "Should I use 'XML::Parser' or 'XML::LibXML'? [XML::LibXML] ";
-  $XML = undef;
-  $answer = <STDIN>;
-  print "\n";
-  if ($answer =~ m/^XML::Parser$/i) {
-    $XML = 'XML::Parser';
-    %req_modules = (%req_modules, $XML => $xmlparser_version);
-  } elsif ($answer =~ m/^\s*$/ || $answer =~ m/^XML::LibXML$/i) {
+#print "\n";
+#print " NOTE: Next versions will, possibly, deprecate XML::Parser backend.\n";
+#print "       At the moment, XML::LibXML is quicker than XML::Parser and\n";
+#print "       supports HTML parsing\n\n";
+#
+#print "I need a XML Back-end (XML::Parser >= $xmlparser_version or XML::LibXML >= $xmllibxml_version\n";
+#do {
+#  print "Sorry, I didn't understand the answer.\n" if ($answer);
+#  print "Should I use 'XML::Parser' or 'XML::LibXML'? [XML::LibXML] ";
+#  $XML = undef;
+#  $answer = <STDIN>;
+#  print "\n";
+#  if ($answer =~ m/^XML::Parser$/i) {
+#    $XML = 'XML::Parser';
+#    %req_modules = (%req_modules, $XML => $xmlparser_version);
+#  } elsif ($answer =~ m/^\s*$/ || $answer =~ m/^XML::LibXML$/i) {
     $XML = 'XML::LibXML';
     %req_modules = (%req_modules, $XML => $xmllibxml_version);
-  }
-} until defined $XML;
+#  }
+#} until defined $XML;
 
 my $pattern = uc($XML);
 
