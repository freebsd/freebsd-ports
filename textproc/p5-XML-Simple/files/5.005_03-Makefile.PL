--- Makefile.PL~	Wed Nov 17 09:43:52 2004
+++ Makefile.PL	Fri Dec  3 18:27:40 2004
@@ -2,17 +2,6 @@
 
 use ExtUtils::MakeMaker;
 
-BEGIN {
-  if($] < 5.006) {
-    warn
-      qq(This version of XML::Simple requires Perl version 5.6 or better.\n) .
-      qq(You might prefer to install an older version of XML::Simple\n\n) .
-      qq(  perl -MCPAN -e "install 'G/GR/GRANTM/XML-Simple-1.08.tar.gz'"\n\n);
-  }
-}
-
-require 5.006;
-
 my $make_params = {
     'NAME'          => 'XML::Simple',
     'VERSION_FROM'  => 'lib/XML/Simple.pm',
