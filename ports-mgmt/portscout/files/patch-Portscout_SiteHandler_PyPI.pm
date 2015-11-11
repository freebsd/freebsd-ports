--- Portscout/SiteHandler/PyPI.pm.orig	2015-10-25 05:00:48 UTC
+++ Portscout/SiteHandler/PyPI.pm
@@ -115,7 +115,7 @@ sub GetFiles
 	    $info = $json->{info};
 	    $version = $info->{version};
 	    next unless $version;
-
+	    _debug("GET success: " . $resp->code . " Filename: " . $json->{releases}{$version}[0]{filename});
 	    push(@$files, $json->{releases}{$version}[0]{filename});
 	} else {
 	    _debug("GET failed: " . $resp->code);
