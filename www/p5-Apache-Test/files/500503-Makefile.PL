--- Makefile.PL.orig	Thu Feb 19 02:40:23 2004
+++ Makefile.PL	Mon Mar 29 17:04:32 2004
@@ -97,6 +97,11 @@
     $string;
 }
 
+sub MY::manifypods	{
+	package MY; my $self=shift;
+	$self->{MAN3PODS}->{'lib/Apache/TestConfig.pm'}='$(INST_MAN3DIR)/Apache::TestConfig.$(MAN3EXT)';
+	$self->SUPER::manifypods(@_);
+}
 sub add_dep {
     my($string, $targ, $add) = @_;
     $$string =~ s/($targ\s+::)/$1 $add/;
