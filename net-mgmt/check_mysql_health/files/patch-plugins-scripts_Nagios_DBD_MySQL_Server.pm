--- plugins-scripts/Nagios/DBD/MySQL/Server.pm.orig	2014-12-07 18:56:47.435107795 +0000
+++ plugins-scripts/Nagios/DBD/MySQL/Server.pm	2014-12-07 18:57:22.394116542 +0000
@@ -310,7 +310,7 @@
   my $message = shift;
   push(@{$self->{nagios}->{messages}->{$level}}, $message);
   # recalc current level
-  foreach my $llevel qw(CRITICAL WARNING UNKNOWN OK) {
+  foreach my $llevel (qw(CRITICAL WARNING UNKNOWN OK)) {
     if (scalar(@{$self->{nagios}->{messages}->{$ERRORS{$llevel}}})) {
       $self->{nagios_level} = $ERRORS{$llevel};
     }
