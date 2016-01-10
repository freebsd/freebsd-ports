--- portscout.pl.orig	2016-01-10 17:42:32 UTC
+++ portscout.pl
@@ -463,7 +463,7 @@ sub VersionCheck
 
 		$i++;
 
-		info($k, 'Checking site: ' . strchop($site, 60));
+		info($k, 'Checking site: ' . strchop($site, 200));
 
 		# Look to see if the URL contains the distfile version.
 		# This will affect our checks and guesses later on.
@@ -493,9 +493,12 @@ sub VersionCheck
 		}
 
 		# Check for special handler for this site first
+		print "Does site handler exist ... "
+			unless ($settings{quiet});
 		if (my $sh = Portscout::SiteHandler->FindHandler($site))
 		{
-			info($k, $site, 'Using dedicated site handler for site.');
+			print "Yes \n"
+				unless ($settings{quiet});
 
 			if (!$sh->GetFiles($site, $port, \@files)) {
 				info($k, $site, 'SiteHandler::GetFiles() failed for ' . $site);
@@ -506,6 +509,9 @@ sub VersionCheck
 		{
 			my $ftp;
 
+			print "No. Trying FTP...\n"
+				unless ($settings{quiet});
+
 			$ftp = Net::FTP->new(
 				$site->host,
 				Port    => $site->port,
@@ -609,6 +615,9 @@ sub VersionCheck
 		{
 			my ($ua, $response);
 
+			print "No. Trying HTTP...\n"
+				unless ($settings{quiet});
+
 			unless (robotsallowed($dbh, $site, $sitedata)) {
 				info($k, $site, 'Ignoring site as per rules in robots.txt.');
 
@@ -713,7 +722,8 @@ sub VersionCheck
 
 				# Got a response which wasn't HTTP 4xx -> bail out
 				if ($response->is_success && $response->status_line !~ /^4/) {
-					info($k, $site, 'Not doing any guessing; site is lieing to us.');
+					print "URL: $url\n";
+					info($k, $site, "Skip guessing: Response not 4xx to a file that shouldnt exist (". $response->status_line .")");
 					$sths->{sitedata_initliecount}->execute($sitedata->{host})
 						unless($settings{precious_data});
 					next;
@@ -797,7 +807,7 @@ sub VersionCheck
 							$new_found = 1;
 							last;
 						} else {
-							info($k, $site, "Guess failed $port->{ver} -> $guess_v");
+							info($k, $site, "Guess failed $port->{ver} -> $guess_v (". $response->status_line .")");
 						}
 
 						last if ($new_found);
@@ -867,7 +877,10 @@ sub FindNewestFile
 
 	foreach my $file (@$files)
 	{
-		my $poss_path;
+		my ($poss_path, $github);
+
+		print "FindNewest: Checking $file ... against port DISTFILES. \n"
+			if ($settings{debug});
 
 		if ($file =~ /^(.*)\/(.*?)$/) {
 			# Files from SiteHandlers can come with paths
@@ -888,6 +901,9 @@ sub FindNewestFile
 
 			my $skip = 0;
 
+			print "FindNewest: Checking DISTFILE ... $distfile (ver: $v, sufx: $s)\n"
+				if ($settings{debug});
+
 			if ($poss_path) {
 				# Do a full-URL comparison for $old_found
 				# if we're dealing with paths too.
@@ -908,14 +924,20 @@ sub FindNewestFile
 			} else {
 				if ($file eq $distfile) {
 					$old_found = 1;
+					print "FindNewest: File matches existing port DISTFILE. Old found. \n"
+						if ($settings{debug});
 					next;
 				}
 			}
 
+			$github = 1 if ($site->clone =~ /^https?:\/\/([^\/.]+\.)?github\.com\/(.*?)\/tar.gz/);
+
 			# Skip beta versions if requested
 
 			if ($port->{skipbeta}) {
 				if (isbeta($file) && !isbeta($distfile)) {
+					print "FindNewest: File is beta, skipbeta is defined. Skipping ...\n"
+						if ($settings{debug});
 					next;
 				}
 			}
@@ -940,31 +962,64 @@ sub FindNewestFile
 
 			# Possible candidate - extract version
 
-			if ($file =~ /^($distfile)$/ && $2)
+			#warn "distfile = $distfile 2 = $2";
+			if (($file =~ /^($distfile)$/ && $2) or $github)
 			{
-				my $version = $2;
-				my $new_v = lc $version;
+				my ($version, $new_v, $matchver);
 
-				# Catch a few missed cases
+				unless ($github) {
+					$version = $2;
+					$new_v = lc $version;
 
-				$new_v =~ s/(?:$ext_regex)$//;
+					# Catch a few missed cases
+					$new_v =~ s/(?:$ext_regex)$//;
 
-				# Version is much longer than original - skip it
+					# Version is much longer than original - skip it
+					next if (length $new_v > (12 + length $old_v));
 
-				next if (length $new_v > (12 + length $old_v));
+					# New version is in date format (or contains a date-like
+					# string) - old one is not. Probably best to ignore.
 
-				# New version is in date format (or contains a date-like
-				# string) - old one is not. Probably best to ignore.
+					next if (
+						$new_v =~ /$date_regex/i &&
+						$old_v !~ /$date_regex/i
+					);
 
-				next if (
-					$new_v =~ /$date_regex/i &&
-					$old_v !~ /$date_regex/i
-				);
+					# Skip a few strange version format change cases
+					# (formatted -> "just a number")
+					next if ($new_v !~ /\./ && $old_v =~ /\./);
+				} else {
+					# Github is "special" since the actual URI we get back from the
+					# handler isn't the same as what is actually being retrieved.
+					# So fall back on comparing tags instead.
 
-				# Skip a few strange version format change cases
-				# (formatted -> "just a number")
+					$new_v = $file;
+					$version = lc $new_v;
 
-				next if ($new_v !~ /\./ && $old_v =~ /\./);
+					# Only match version-esque looking strings from the tag
+					# because portscout currently only uses/stores a normalized
+					# 'ver', not PORTVERSION or DISTVERSION{FULL} so we have nothing
+					# canonical to compare agains. Currently the match is for digits
+					# with any non-digit separators, without non-digit prefixes and
+					# suffixes. This is likely the best we can get for now, without
+					# introducing false positives.
+
+					($matchver) = ($version =~ m/((?:\d+.)*\d+)/);
+
+					print "FindNewestFile::Github: Input: $file Matchver: $matchver \n"
+						if ($settings{debug});
+					
+					# Replace non-digit separators of digits with dots.
+
+					$matchver =~ s/[^\d+]/\./g;
+
+					if (defined($matchver)) {
+						$new_v = $matchver;
+					}
+
+					print "FindNewestFile::Github: Matchver: $matchver Normalized: $new_v \n" 
+						if ($settings{debug});
+				}
 
 				# Skip any specific versions if requested
 
@@ -973,6 +1028,8 @@ sub FindNewestFile
 
 					foreach (split (/\s+/, $port->{skipversions})) {
 						if ($new_v eq $_) {
+							print "FindNewest: skipversions is defined. Matched $_. Skipping...\n"
+								if ($settings{debug});
 							$skip = 1;
 							last;
 						}
@@ -981,7 +1038,7 @@ sub FindNewestFile
 					next if ($skip);
 				}
 
-				unless ($settings{sillystrings_enable}) {
+				unless ($settings{sillystrings_enable} or $github) {
 					if ($new_v =~ /[-_.]([A-Za-z]+[A-Za-z_-]{2,})$/) {
 						my $str = $1;
 						next if (
@@ -1026,12 +1083,19 @@ sub FindNewestFile
 
 				# Test our new version string
 
+				print "FindNewest: Comparing Old ($old_v) vs New ($new_v) version strings... \n"
+					if ($settings{debug});
+
 				if ($new_v eq $old_v)
 				{
+					print "FindNewest: Old ($old_v) == New ($new_v). Old found.\n"
+						if ($settings{debug});
 					$old_found = 1;
 				}
 				elsif (vercompare($new_v, $old_v))
 				{
+					print "FindNewest: Old ($old_v) < New ($new_v). New found.\n"
+						if ($settings{debug});
 					$new_found = 1;
 
 					# Keep going until we find the newest version
