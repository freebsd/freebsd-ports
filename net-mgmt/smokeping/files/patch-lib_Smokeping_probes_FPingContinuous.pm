--- lib/Smokeping/probes/FPingContinuous.pm.orig	2021-08-13 06:20:13 UTC
+++ lib/Smokeping/probes/FPingContinuous.pm
@@ -72,8 +72,8 @@ sub new($$$)
     	my $binary = join(" ", $self->binary);
 	my $testhost = $self->testhost;
 	my $return = `$binary -C 1 $testhost 2>&1`;
-	$self->{enable}{S} = (`$binary -h 2>&1` =~ /\s-S\s/);
-	$self->{enable}{O} = (`$binary -h 2>&1` =~ /\s-O\s/);
+	$self->{enable}{S} = (`$binary -h 2>&1` =~ /\s-S[,\s]/);
+	$self->{enable}{O} = (`$binary -h 2>&1` =~ /\s-O[,\s]/);
 	croak "ERROR: fping ('$binary -C 1 $testhost') could not be run: $return"
 	    if $return =~ m/not found/;
 	croak "ERROR: FPing must be installed setuid root or it will not work\n" 
