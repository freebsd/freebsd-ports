--- Makefile.PL.orig	2011-04-13 08:20:54 UTC
+++ Makefile.PL
@@ -103,24 +103,6 @@ WriteMakefile(
 );
 
 
-sub MY::install {
-    package MY;
-    my $script = shift->SUPER::install(@_);
-    if (ExtUtils::MakeMaker::prompt("Do you want to alter ParserDetails.ini?", "Y") =~ /^y/i) {
-        $script =~ s/install :: (.*)$/install :: $1 install_expat_xs/m;
-        $script .= <<"INSTALL";
-
-install_expat_xs :
-\t\@\$(PERL) -MXML::SAX -e "XML::SAX->add_parser(q(XML::SAX::ExpatXS))->save_parsers()"
-
-INSTALL
-
-    }
-
-    return $script;
-}
-
-
 sub build_xml_sax_expatxs_preload {
     
     print "Writing XML::SAX::ExpatXS::Preload\n";
