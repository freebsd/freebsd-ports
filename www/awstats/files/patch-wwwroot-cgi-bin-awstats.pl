--- wwwroot/cgi-bin/awstats.pl.orig	2011-07-06 08:11:37.000000000 +0100
+++ wwwroot/cgi-bin/awstats.pl	2011-07-06 08:16:32.000000000 +0100
@@ -1353,9 +1353,7 @@
 #------------------------------------------------------------------------------
 sub OptimizeArray {
 	my $array = shift;
-	my @arrayunreg = map {
-		if (/\(\?[-\w]*:(.*)\)/) { $1 }
-	} @$array;
+	my @arrayunreg = map { UnCompileRegex($_) } @$array;
 	my $notcasesensitive = shift;
 	my $searchlist       = 0;
 	if ($Debug) {
@@ -3049,7 +3047,7 @@
 # Debian package :                    		"/usr/share/awstats/plugins"
 	my @PossiblePluginsDir = (
 		"$DIR/plugins",
-		"/usr/local/awstats/wwwroot/cgi-bin/plugins",
+		"%%PREFIX%%/www/awstats/cgi-bin/plugins",
 		"/usr/share/awstats/plugins"
 	);
 	my %DirAddedInINC = ();
@@ -7809,7 +7807,7 @@
 # Return:		standardregex
 #------------------------------------------------------------------------------
 sub UnCompileRegex {
-	shift =~ /\(\?[-\w]*:(.*)\)/;
+	shift =~ /\(\?[-^\w]*:(.*)\)/;
 	return $1;
 }
 
