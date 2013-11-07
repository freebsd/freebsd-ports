--- Makefile.PL.orig	2013-11-07 09:23:43.000000000 +0800
+++ Makefile.PL	2013-11-07 09:25:19.000000000 +0800
@@ -28,10 +28,7 @@ sub MY::install {
     else {
         my $dir = File::Basename::dirname($INC{'XML/SAX.pm'});
         if (-e File::Spec->catfile($dir, 'SAX', 'ParserDetails.ini')) {
-            $write_ini_ok =
-                ExtUtils::MakeMaker::prompt(
-                    "Do you want XML::SAX to alter ParserDetails.ini?", "Y"
-                ) =~ /^y/i;
+            $write_ini_ok = %%WRITE_INI_OK%%;
         }
         else {
             $write_ini_ok = 1;
@@ -43,7 +40,7 @@ sub MY::install {
         $script .= <<"INSTALL";
 
 install_sax_pureperl :
-\t\@\$(PERL) -MXML::SAX -e "XML::SAX->add_parser(q(XML::SAX::PurePerl))->save_parsers()"
+\t\@\$(PERL) -I\$(DESTDIR)\$(INSTALLSITELIB) -MXML::SAX -e "XML::SAX->add_parser(q(XML::SAX::PurePerl))->save_parsers()"
 
 INSTALL
 
