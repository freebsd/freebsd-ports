--- Portscout/SiteHandler/PyPI.pm.orig	2016-02-04 08:23:53 UTC
+++ Portscout/SiteHandler/PyPI.pm
@@ -109,11 +109,13 @@ sub GetFiles
 	$ua->agent(USER_AGENT);
 	$resp = $ua->request(HTTP::Request->new(GET => $query));
 	if ($resp->is_success) {
+	    _debug("GET success: " . $resp->code);
 	    my ($json, $urls);
 
 	    $json = decode_json($resp->decoded_content);
 	    $urls = $json->{urls};
 	    foreach my $url (@$urls) {
+		_debug("PyPi File: " . $url->{filename});
 		push(@$files, $url->{filename});
 	    }
 	} else {
