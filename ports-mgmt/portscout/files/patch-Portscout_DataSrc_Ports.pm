--- Portscout/DataSrc/Ports.pm.orig	2019-10-11 12:05:53 UTC
+++ Portscout/DataSrc/Ports.pm
@@ -454,6 +454,8 @@ sub BuildPort
 		$site =~ s/\/+$/\//;
 		$site =~ s/:[A-Za-z0-9][A-Za-z0-9\,]*$//g; # site group spec.
 
+		next if ($site eq "");
+
 		$site = URI->new($site)->canonical;
 		next if (length $site->host == 0);
 
