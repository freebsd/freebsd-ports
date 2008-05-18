
$FreeBSD$

--- lib/ASmain.pl.orig
+++ lib/ASmain.pl
@@ -41,20 +41,20 @@
 # Create the whole IPv6 BGP ASpath tree
 	my $lastchange_time = &check_update_changes(0);
 	&create_html_tree(0, $lastchange_time);
-	if ($MORETREES) {
+#	if ($MORETREES) {
 # Create the IPv6 BGP ASpath tree for the 6Bone backbone
-		$lastchange_time = &check_update_changes(1);
-		&create_html_tree(1, $lastchange_time);
+#		$lastchange_time = &check_update_changes(1);
+#		&create_html_tree(1, $lastchange_time);
 
 # Create the IPv6 BGP ASpath tree for the other IANA assigned prefixes
-		$lastchange_time = &check_update_changes(3);
-		&create_html_tree(3, $lastchange_time);
-	}
+#		$lastchange_time = &check_update_changes(3);
+#		&create_html_tree(3, $lastchange_time);
+#	}
 	&log_it("  Tree page(s): done",1);
 # Create routes stability pages
 #     for the 6bone backbone
-	&create_stability_page("$HTMLDIR_LOCAL/ptla-stability.html", "ptla");
-	&log_it("  bb stability page: done",1);
+#	&create_stability_page("$HTMLDIR_LOCAL/ptla-stability.html", "ptla");
+#	&log_it("  bb stability page: done",1);
 #     for the other IANA assigned prefixes
 	&create_stability_page("$HTMLDIR_LOCAL/200x-stability.html", "stla");
 	&log_it("  IANA stability page: done",1);
@@ -113,7 +113,7 @@
 		system "cp $HTMLDIR_LOCAL/odd-routes*.html $HTMLDIR/";
 		system "cp $HTMLDIR_LOCAL/odd-asnumbers*.html $HTMLDIR/";
 		system "cp $HTMLDIR_LOCAL/200x-stability.html $HTMLDIR";
-		system "cp $HTMLDIR_LOCAL/ptla-stability.html $HTMLDIR";
+#		system "cp $HTMLDIR_LOCAL/ptla-stability.html $HTMLDIR";
 
 		system "cp $HTMLDIR_LOCAL/$INDEXPAGE $HTMLDIR/$INDEXPAGE";
 		&log_it("  Done!",1);
