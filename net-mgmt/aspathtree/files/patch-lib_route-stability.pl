
$FreeBSD$

--- lib/route-stability.pl.orig
+++ lib/route-stability.pl
@@ -10,7 +10,7 @@
 	my ($ptlaprefix, $viewlink, $unstab, $unav, $key, $name, $title, $history_reldir);
 
 	if ($type eq "ptla") {$title = "6bone pTLAs: BGP route stability"}
-	elsif ($type eq "stla") {$title = "sTLAs: BGP route stability"}
+	elsif ($type eq "stla") {$title = "IPv6: BGP route stability"}
 	else {return(1)}
 
 	$history_reldir = substr($HISTORYHTMLDIR, length($HTMLDIR_LOCAL) + 1, length($HISTORYHTMLDIR) - length($HTMLDIR_LOCAL));
@@ -120,7 +120,7 @@
 		</TABLE></CENTER>\n
 		<P><SPAN CLASS=n10><A HREF=\"./$INDEXPAGE\">Back to routing information page</A><P>\n
 		<HR>\n
-		This page displays all the locally known sTLAs that are advertised inside the 6Bone backbone.
+		This page displays all the locally known allocations that are advertised inside the IPv6 backbone.
 	        For each IPv6 BGP route entry, figures representing instability and unavailability of are provided.
 	        Ruote entries are sorted starting from the most unstable route entry.<BR>
 	        These figures are calculated based on periodical snapshots of the IPv6 BGP routing table as follows:
@@ -128,7 +128,7 @@
 	        was a detection of AS Path changes for the specific route and the number of snapshots in the last 24 hours
 	        <LI><SPAN CLASS=r10>Unavailability</SPAN>: the ratio between the number of times the route
 	        was not present and the number of snapshots in the last 24 hours</UL>
-		Clicking on \&quot;view\&quot; for each sTLA you can get more detailed information about routing stability
+		Clicking on \&quot;view\&quot; for each IPv6 prefix you can get more detailed information about routing stability
 		in the last 24 hours.
 	        ";
 	}
