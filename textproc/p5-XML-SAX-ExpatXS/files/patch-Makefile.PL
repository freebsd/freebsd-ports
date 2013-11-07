--- Makefile.PL.orig	2013-11-07 09:32:26.000000000 +0800
+++ Makefile.PL	2013-11-07 09:32:53.000000000 +0800
@@ -111,7 +111,7 @@ sub MY::install {
         $script .= <<"INSTALL";
 
 install_expat_xs :
-\t\@\$(PERL) -MXML::SAX -e "XML::SAX->add_parser(q(XML::SAX::ExpatXS))->save_parsers()"
+\t\@\$(PERL) -I\$(DESTDIR)\$(INSTALLSITELIB)/mach -MXML::SAX -e "XML::SAX->add_parser(q(XML::SAX::ExpatXS))->save_parsers()"
 
 INSTALL
 
