--- beacon.pl.orig	Thu Feb 26 13:58:02 2004
+++ beacon.pl	Thu Feb 26 13:58:35 2004
@@ -1849,7 +1849,7 @@
 		die("Partial options specified -- You must give group, port, and ttl values - Triggered");
 	} else {	# Didn't specify any options at all -- Use default config file
 		if (! defined $CONFIGFILE) {		# They DIDN'T specify a config file on the command line
-			$CONFIGFILE = "beacon.conf";	# Default config file for Beacon -- Otherwise, use what they gave us
+			$CONFIGFILE = "${PREFIX}/etc/beacon.conf";	# Default config file for Beacon -- Otherwise, use what they gave us
 		}
 	}
   }
