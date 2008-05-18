
$FreeBSD$

--- lib/bgp-tree.pl.orig
+++ lib/bgp-tree.pl
@@ -131,7 +131,7 @@
 	}
 	elsif ($tree_type == 3) { # otherIANA
 		$output_file = $OUTPUTIANA;
-		$title = "IPv6 BGP table: &quot;2001&quot; routes";
+		$title = "IPv6 BGP table: the routes";
 	}
 
 	open(HTMLFILE,">".$output_file);
@@ -215,8 +215,8 @@
 			print HTMLFILE "		<SPAN CLASS=n12>$lastchange on the tree detected on $printable_date</SPAN><BR><HR>\n";
 		}
 		print HTMLFILE "
-		<SPAN CLASS=n10>The IPv6 BGP routing tree for the &quot;2001&quot; routes (route entries containing prefixes assigned by the RIRs
-                within the 2001::/16 address space and prefix length in range [29,35]) is obtained elaborating the AS path
+		<SPAN CLASS=n10>The IPv6 BGP routing tree for route entries containing prefixes assigned by the RIRs
+                and prefix length in range [19,32]) is obtained elaborating the AS path
 		information of the IPv6 BGP routing table.<BR>
 		A link to detailed routing information is available at the end of each branch
 		of the tree.<BR>
@@ -268,7 +268,7 @@
 	print HTMLDETAILS "<TD BGCOLOR=\"$LINESDETTABLECOLOR\"><IMG SRC=\"../../$ICONS/p.gif\"></TD>\n";
 	print HTMLDETAILS "<TD ALIGN=center CLASS=n10b>&nbsp;Assigned to&nbsp;</TD>\n";
 	print HTMLDETAILS "<TD BGCOLOR=\"$LINESDETTABLECOLOR\"><IMG SRC=\"../../$ICONS/p.gif\"></TD>\n";
-	print HTMLDETAILS "<TD ALIGN=center CLASS=n10b>&nbsp;xTLA owner&nbsp;</TD>\n";
+	print HTMLDETAILS "<TD ALIGN=center CLASS=n10b>&nbsp;IPv6 owner&nbsp;</TD>\n";
 	print HTMLDETAILS "<TD BGCOLOR=\"$LINESDETTABLECOLOR\"><IMG SRC=\"../../$ICONS/p.gif\"></TD>\n";
 	print HTMLDETAILS "<TD ALIGN=center CLASS=n10b>Time&nbsp;(updates)<BR>&nbsp;since last change&nbsp;</TD>\n";
 	print HTMLDETAILS "<TD BGCOLOR=\"$LINESDETTABLECOLOR\"><IMG SRC=\"../../$ICONS/p.gif\"></TD>\n";
