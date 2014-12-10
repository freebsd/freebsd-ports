--- plugins-scripts/Nagios/DBD/MySQL/Cluster.pm.orig	2014-12-07 18:40:22.318185465 +0000
+++ plugins-scripts/Nagios/DBD/MySQL/Cluster.pm	2014-12-07 18:41:15.780179599 +0000
@@ -192,7 +192,7 @@
   my $message = shift;
   push(@{$self->{nagios}->{messages}->{$level}}, $message);
   # recalc current level
-  foreach my $llevel qw(CRITICAL WARNING UNKNOWN OK) {
+  foreach my $llevel (qw(CRITICAL WARNING UNKNOWN OK)) {
     if (scalar(@{$self->{nagios}->{messages}->{$ERRORS{$llevel}}})) {
       $self->{nagios_level} = $ERRORS{$llevel};
     }
