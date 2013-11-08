--- Makefile.PL.orig	2011-09-05 05:37:48.000000000 +0800
+++ Makefile.PL	2013-11-09 01:00:33.000000000 +0800
@@ -27,15 +27,7 @@ sub MY::install {
     }
     else {
         my $dir = File::Basename::dirname($INC{'XML/SAX.pm'});
-        if (-e File::Spec->catfile($dir, 'SAX', 'ParserDetails.ini')) {
-            $write_ini_ok =
-                ExtUtils::MakeMaker::prompt(
-                    "Do you want XML::SAX to alter ParserDetails.ini?", "Y"
-                ) =~ /^y/i;
-        }
-        else {
-            $write_ini_ok = 1;
-        }
+        $write_ini_ok = 1;
     }
     
     if ($write_ini_ok) {
@@ -43,7 +35,7 @@ sub MY::install {
         $script .= <<"INSTALL";
 
 install_sax_pureperl :
-\t\@\$(PERL) -MXML::SAX -e "XML::SAX->add_parser(q(XML::SAX::PurePerl))->save_parsers()"
+\t\@\$(PERL) -I\$(DESTDIR)\$(INSTALLSITELIB) -MXML::SAX -e "XML::SAX->add_parser(q(XML::SAX::PurePerl))->save_parsers()"
 
 INSTALL
 
