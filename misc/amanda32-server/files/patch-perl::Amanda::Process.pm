--- perl/Amanda/Process.pm.orig	2009-01-28 13:57:55.000000000 +0900
+++ perl/Amanda/Process.pm	2009-01-28 13:58:19.000000000 +0900
@@ -155,7 +155,7 @@
     $self->{ppid} = ();
     my $ps_argument = $Amanda::Constants::PS_ARGUMENT;
     if ($ps_argument eq "CYGWIN") {
-	open(PSTABLE, "-|", "ps -ef") || die("ps -ef: $!");
+	open(PSTABLE, "-|", "ps -f") || die("ps -f: $!");
 	my $psline = <PSTABLE>; #header line
 	while($psline = <PSTABLE>) {
 	    chomp $psline;
