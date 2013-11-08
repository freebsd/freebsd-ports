--- Makefile.PL.orig	2013-11-08 19:55:12.000000000 +0800
+++ Makefile.PL	2013-11-08 19:55:54.000000000 +0800
@@ -36,7 +36,7 @@ sub MY::install {
       $script .= <<"INSTALL";
 
 install_sax_expat :
-\t\@\$(PERL) -I\$(INSTALLSITELIB) -MXML::SAX -e "XML::SAX->add_parser(q(XML::SAX::Expat))->save_parsers()"
+\t\@\$(PERL) -I\$(DESTDIR)\$(INSTALLSITELIB) -MXML::SAX -e "XML::SAX->add_parser(q(XML::SAX::Expat))->save_parsers()"
 
 INSTALL
     } else {
