--- Makefile.PL.orig	Wed Feb 18 23:24:44 2004
+++ Makefile.PL	Tue Jul 20 15:40:48 2004
@@ -97,6 +97,12 @@
     $string;
 }
 
+sub MY::manifypods	{
+	package MY; my $self=shift;
+	$self->{MAN3PODS}->{'lib/Apache/TestConfig.pm'}='$(INST_MAN3DIR)/Apache::TestConfig.$(MAN3EXT)';
+	$self->{MAN3PODS}->{'lib/Apache/TestConfigData.pm'}='$(INST_MAN3DIR)/Apache::TestConfigData.$(MAN3EXT)';
+	$self->SUPER::manifypods(@_);
+}
 sub add_dep {
     my($string, $targ, $add) = @_;
     $$string =~ s/($targ\s+::)/$1 $add/;
