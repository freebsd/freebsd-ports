
$FreeBSD$

--- lib/odd-routes.pl.orig
+++ lib/odd-routes.pl
@@ -308,14 +308,12 @@
 	print HTMLFILE "
 	<HR>\n
 	This pages display all the anomalous IPv6 BGP prefixes (according to RFC2546 - &quot;IPv6 routing Practice&quot;)
-	currently advertised inside the 6Bone backbone. In particular two kinds of anomalous prefixes are displayed:
+	currently advertised inside the IPv6 backbone. In particular two kinds of anomalous prefixes are displayed:
 	<UL>\n
 	<LI><SPAN CLASS=r10>Invalid prefixes</SPAN>: prefixes outside of the IANA assigned address spaces
-	(e.g. the old RFC1897 test addresses)\n
-	<LI><SPAN CLASS=r10>Unaggregated prefixes</SPAN>: prefixes belonging to the 6Bone range
-	but longer than a given pTLA delegation (according to RFC2546 these
-	prefixes MUST NOT be advertised unless special peering agreements are implemented); prefixes
-	belonging to the RIR&quot;s delegations but longer than assigned sTLAs.\n
+	(e.g. the old RFC1897 test addresses, 6Bone addresses)\n
+	<LI><SPAN CLASS=r10>Unaggregated prefixes</SPAN>: 
+	prefixes belonging to the RIR&quot;s delegations but longer than assigned allocation.\n
 	</UL>
 	<HR>\n".&footer."
 	</SPAN>\n</BODY>\n</HTML>\n";
