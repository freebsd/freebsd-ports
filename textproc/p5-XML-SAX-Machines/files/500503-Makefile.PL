--- Makefile.PL.orig	Wed Dec 29 20:16:15 2004
+++ Makefile.PL	Wed Dec 29 20:18:39 2004
@@ -49,3 +49,9 @@
 install_site_config:
 	$(PERL) -I$(PERL_ARCHLIB) -I$(PERL_LIB) -I$(INST_LIB) -I$(INSTALLSITELIB) -MXML::SAX::Machines::ConfigHelper -we 'XML::SAX::Machines::ConfigHelper::_write_site_config_if_absent(shift)' $(INSTALLSITELIB)
 POSTAMBLE_END
+
+sub MY::manifypods	{
+	package MY; my $self=shift;
+	$self->{MAN3PODS}->{'lib/XML/SAX/Machines/ConfigHelper.pm'}='$(INST_MAN3DIR)/XML::SAX::Machines::ConfigHelper.$(MAN3EXT)';
+	$self->SUPER::manifypods(@_);
+}
