
$FreeBSD$

--- lib/create-homepage.pl.orig
+++ lib/create-homepage.pl
@@ -149,17 +149,16 @@
           <SPAN CLASS=a18b>Graphic display</SPAN> of:
           <UL>
           <LI><A HREF=\"bgp-page-complete.html\" CLASS=l12b>all route entries within the IPv6 BGP cloud</A><BR>\n";
-	if ($MORETREES) {
-		print OUT_FILE "          <LI><A HREF=\"bgp-page-backbone.html\" CLASS=l12b>the 6Bone backbone BGP tree</A><BR>
-          <LI><A HREF=\"bgp-page-otherIANA.html\" CLASS=l12b>the BGP tree for prefixes assigned by the RIRs</A>\n";
-	}
+#	if ($MORETREES) {
+#		print OUT_FILE "          <LI><A HREF=\"bgp-page-backbone.html\" CLASS=l12b>the 6Bone backbone BGP tree</A><BR>
+#          <LI><A HREF=\"bgp-page-otherIANA.html\" CLASS=l12b>the BGP tree for prefixes assigned by the RIRs</A>\n";
+#	}
 	print OUT_FILE "          </UL>\n";
 
 	if ($$inumelab{N_6to4}) {$sixto4link = "<LI>the 6to4 prefix"}
 
 	print OUT_FILE "          <SPAN CLASS=a18b>Prefix analysis</SPAN>(*):<BR>
           <UL>
-          <LI>$$inumelab{N_ptlas} 6Bone pTLAs
           <LI>$$inumelab{N_otherIANA} prefixes assigned by RIRs (prefix length in range [29,35])
           $sixto4link\n";
 	if ($$inumelab{N_invalid} || $$inumelab{N_unaggr} || $$inumelab{N_longer6to4}) {
@@ -167,7 +166,7 @@
           <UL>
           <LI TYPE=square>$$inumelab{N_invalid} invalid prefixes (out of allocated public address space)</LI>
           <LI TYPE=square>$$inumelab{N_unaggr} unaggregated prefixes, sorted <A HREF=\"odd-routes1.html\" CLASS=l12b> by origin AS</A>
-          and <A HREF=\"odd-routes2.html\" CLASS=l12b>by xTLA owner</A></LI>\n";
+          and <A HREF=\"odd-routes2.html\" CLASS=l12b>by IPv6 allocation owner</A></LI>\n";
 		if ($$inumelab{N_longer6to4}) {
 			print OUT_FILE "          <LI TYPE=square>$$inumelab{N_longer6to4} <A HREF=\"odd-routes3.html\" CLASS=l12b>6to4 longer prefixes</A></LI>\n";
 		}
@@ -182,8 +181,7 @@
 print OUT_FILE "          <SPAN CLASS=a18b>Routing stability analysis</SPAN>
           during the last 24 hours for:<BR>
           <UL>
-          <LI><A HREF=\"ptla-stability.html\" CLASS=l12b>all the 6Bone pTLAs</A><BR>
-          <LI><A HREF=\"200x-stability.html\" CLASS=l12b>the sTLAs assigned by the RIRs</A>
+          <LI><A HREF=\"200x-stability.html\" CLASS=l12b>the IPv6 adresses assigned by the RIRs</A>
           </UL>
         </TD></TR>
       </TABLE>
@@ -249,7 +247,7 @@
 sub footer {
 	my $footer = "This page has been produced using the
 	<A HREF=\"http://carmen.ipv6.tilab.com/ipv6/tools/ASpath-tree/index.html\">ASpath-tree</A> tool ($VER),
-	developed at <A HREF=\"http://www.telecomitalialab.com\">Telecom Italia Lab</A> (formerly CSELT).<BR>
+	developed at <A HREF=\"http://www.telecomitalialab.com\">Telecom Italia Lab</A> (formerly CSELT). and NIIF<BR>
 	Questions and comments to: <A HREF=\"mailto:$CONTACTMAIL\">$CONTACTNAME</A>\n";
 	return($footer);
 }
