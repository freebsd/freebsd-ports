Patch for rt.cpan.org ticket 14155
--- lib/Net/Server.pm.orig	Tue Sep  6 13:50:52 2005
+++ lib/Net/Server.pm	Tue Sep  6 13:50:59 2005
@@ -49,7 +49,7 @@
 
   ### save for a HUP
   my $script = $0;
-  $script = $ENV{'PWD'} .'/'. $0 if $ENV{'PWD'};
+  $script = $ENV{'PWD'} .'/'. $0 if exists $ENV{'PWD'} and $script !~ m(^/);
   $self->{server}->{commandline} = [ $script, @ARGV ]
     unless defined $self->{server}->{commandline};
 
