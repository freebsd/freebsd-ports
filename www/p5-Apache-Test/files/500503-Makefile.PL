--- Makefile.PL.orig	Tue Jul 29 19:24:18 2003
+++ Makefile.PL	Tue Jul 29 19:25:42 2003
@@ -73,6 +73,11 @@
     return $string;
 }
 
+sub MY::manifypods	{
+	package MY; my $self=shift;
+	$self->{MAN3PODS}->{'lib/Apache/TestConfig.pm'}='$(INST_MAN3DIR)/Apache::TestConfig.$(MAN3EXT)';
+	$self->SUPER::manifypods(@_);
+}
 
 sub add_dep {
     my($string, $targ, $add) = @_;
