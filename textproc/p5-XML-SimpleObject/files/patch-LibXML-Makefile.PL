--- LibXML/Makefile.PL.orig	Fri Sep  5 09:11:38 2003
+++ LibXML/Makefile.PL	Fri Sep  5 09:11:56 2003
@@ -9,5 +9,5 @@
 print "OK\n";
 WriteMakefile(
     'NAME'	=> 'XML::SimpleObject::LibXML',
-    'VERSION_FROM' => 'LibXML.pm', # finds $VERSION
+    'VERSION' => '0.53',
 );
