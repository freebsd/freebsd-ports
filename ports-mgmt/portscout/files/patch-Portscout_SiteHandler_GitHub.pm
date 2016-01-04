--- Portscout/SiteHandler/GitHub.pm.orig	2016-01-04 10:46:49 UTC
+++ Portscout/SiteHandler/GitHub.pm
@@ -97,7 +97,9 @@ sub GetFiles
 	my ($url, $port, $files) = @_;
 	my $projname;
 
-	if ($url =~ /https:\/\/github\.com\/(.*?)\/archive\//) {
+	if ($url =~ /https?:\/\/codeload\.github\.com\/(.*?)\/tar.gz\//) {
+	    $projname = $1;
+	} elsif ($url =~ /https:\/\/github\.com\/(.*?)\/archive\//) {
 	    $projname = $1;
 	} elsif ($url =~ /https:\/\/github.com\/downloads\/(.*)\//) {
 	    $projname = $1;
@@ -108,7 +110,11 @@ sub GetFiles
 
 		# First check if there's a latest releases endpoint
 		$query = 'https://api.github.com/repos/' . $projname . '/releases/latest';
-
+		# Add GitHub Client ID & Secret if they are set in settings
+		# https://developer.github.com/v3/#authentication
+		if ($settings{github_client_id} && $settings{github_client_secret}) {
+			$query = $query . "?client_id=$settings{github_client_id}&client_secret=$settings{github_client_secret}";
+		}
 		_debug("GET $query");
 		$ua = LWP::UserAgent->new;
 		$ua->agent(USER_AGENT);
@@ -120,6 +126,11 @@ sub GetFiles
 			_debug('GET failed: ' . $response->status_line);
 			# Project didn't do any releases, so let's try tags instead.
 			$query = 'https://api.github.com/repos/' . $projname . '/tags';
+			# Add GitHub Client ID & Secret if they are set in settings
+			# https://developer.github.com/v3/#authentication
+			if ($settings{github_client_id} && $settings{github_client_secret}) {
+				$query = $query . "?client_id=$settings{github_client_id}&client_secret=$settings{github_client_secret}";
+			}
 			_debug("GET $query");
 			$ua = LWP::UserAgent->new;
 			$ua->agent(USER_AGENT);
