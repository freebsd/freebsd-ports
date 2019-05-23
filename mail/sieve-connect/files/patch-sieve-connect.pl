--- sieve-connect.pl.orig	2019-05-23 07:31:11 UTC
+++ sieve-connect.pl
@@ -927,7 +927,7 @@ if (defined $realm) {
 		if (/^"(.*)"\r?\n?$/) {
 			$challenge = $1;
 		} else {
-			unless (/^{(\d+)\+?}\r?$/m) {
+			unless (/^\{(\d+)\+?}\r?$/m) {
 				sfinish $sock, "*";
 				closedie($sock, "Failure to parse server SASL response.\n");
 			}
@@ -1510,7 +1510,7 @@ sub sieve_download
 		warn qq{Empty script "$remotefn"?  Not saved.\n};
 		return;
 	}
-	unless (/^{(\d+)\+?}\r?$/m) {
+	unless (/^\{(\d+)\+?}\r?$/m) {
 		die "QUIT:Failed to parse server response to GETSCRIPT";
 	}
 	my $contentdata = $_;
@@ -1526,7 +1526,7 @@ sub sieve_download
 			or die "write-open($localfn) failed: $!\n";
 		$oldouthandle = select $fh;
 	}
-	$contentdata =~ s/^{\d+\+?}\r?\n?//m;
+	$contentdata =~ s/^\{\d+\+?}\r?\n?//m;
 	print $contentdata;
 	select $oldouthandle if defined $oldouthandle;
 	if (defined $fh) {
