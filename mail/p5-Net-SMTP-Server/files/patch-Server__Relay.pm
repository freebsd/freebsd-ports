--- ./Server/Relay.pm.orig	2014-08-29 12:29:32.000000000 -0400
+++ ./Server/Relay.pm	2014-08-29 12:30:08.000000000 -0400
@@ -24,7 +24,7 @@
     # Loop through the recipient list.
     foreach $target (@{$self->{TO}}) {
 	my $rr;
-	my $domain = /@(.*)/;
+	my $domain = ($target =~ /@(.*)/) ? $1 : hostdomain;
 	my $res = new Net::DNS::Resolver;
 	my @mx = mx($res, defined($1) ? $1 : hostdomain);
 	
