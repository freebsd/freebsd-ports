--- lib/Mail/SpamAssassin/Plugin/DCC.pm	(revision 905273)
+++ lib/Mail/SpamAssassin/Plugin/DCC.pm	(working copy)
@@ -679,7 +679,7 @@
   my $left;
   my $right;
   my $timeout = $conf->{dcc_timeout};
-  my $opts = $conf->{dcc_options};
+  my $opts = $conf->{dccifd_options};
   my @opts = !defined $opts ? () : split(' ',$opts);
 
   $permsgstatus->enter_helper_run_mode();
@@ -906,7 +906,7 @@
   my $conf = $self->{main}->{conf};
   my $timeout = $conf->{dcc_timeout};
   # instead of header use whatever the report option is
-  my $opts = $conf->{dcc_options};
+  my $opts = $conf->{dccifd_options};
   my @opts = !defined $opts ? () : split(' ',$opts);
 
   $options->{report}->enter_helper_run_mode();

