--- perl/Amanda/Process.pm.orig	2017-12-01 13:26:29 UTC
+++ perl/Amanda/Process.pm
@@ -184,7 +184,7 @@ sub load_ps_table() {
     $self->{ppid} = ();
     my $ps_argument = $Amanda::Constants::PS_ARGUMENT;
     if ($ps_argument eq "CYGWIN") {
-	open(PSTABLE, "-|", "ps -ef") || die("ps -ef: $!");
+	open(PSTABLE, "-|", "ps -f") || die("ps -f: $!");
 	my $psline = <PSTABLE>; #header line
 	while($psline = <PSTABLE>) {
 	    chomp $psline;
