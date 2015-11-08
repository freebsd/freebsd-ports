--- portscout.pl.orig	2015-10-25 05:00:48 UTC
+++ portscout.pl
@@ -463,7 +463,7 @@ sub VersionCheck
 
 		$i++;
 
-		info($k, 'Checking site: ' . strchop($site, 60));
+		info($k, 'Checking site: ' . strchop($site, 200));
 
 		# Look to see if the URL contains the distfile version.
 		# This will affect our checks and guesses later on.
@@ -493,15 +493,23 @@ sub VersionCheck
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
 				next;
 			}
 		}
+                elsif (!$sh)
+		{
+			print "No \n"
+				unless ($settings{quiet});
+		}
 		elsif ($site->scheme eq 'ftp')
 		{
 			my $ftp;
@@ -713,7 +721,8 @@ sub VersionCheck
 
 				# Got a response which wasn't HTTP 4xx -> bail out
 				if ($response->is_success && $response->status_line !~ /^4/) {
-					info($k, $site, 'Not doing any guessing; site is lieing to us.');
+					print "URL: $url\n";
+					info($k, $site, "Skip guessing: Response not 4xx to a file that shouldnt exist (". $response->status_line .")");
 					$sths->{sitedata_initliecount}->execute($sitedata->{host})
 						unless($settings{precious_data});
 					next;
@@ -797,7 +806,7 @@ sub VersionCheck
 							$new_found = 1;
 							last;
 						} else {
-							info($k, $site, "Guess failed $port->{ver} -> $guess_v");
+							info($k, $site, "Guess failed $port->{ver} -> $guess_v (". $response->status_line .")");
 						}
 
 						last if ($new_found);
