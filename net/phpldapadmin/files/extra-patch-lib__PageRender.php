--- lib/QueryRender.php.orig	2019-08-07 01:14:46.000000000 +0200
+++ lib/QueryRender.php	2019-09-02 10:45:44.632080000 +0200
@@ -284,10 +284,10 @@ class QueryRender extends PageRender {
 
 							# Ignore DN, we've already displayed it.
 							if ($attr == 'dn')
-								continue;
+								continue 2;
 
 							if (! isset($dndetails[$attr]))
-								continue;
+								continue 2;
 
 							# Set our object with our values
 							$afattrs[$attr]->clearValue();
@@ -321,7 +321,7 @@ class QueryRender extends PageRender {
 					if (! $results) {
 						echo _('Search returned no results');
 
-						continue;
+						continue 2;
 					}
 
 					printf('<form action="cmd.php" method="post" id="massform_%s">',$counter);
@@ -374,7 +374,7 @@ class QueryRender extends PageRender {
 							# If the entry is blank, we'll draw an empty box and continue.
 							if (! isset($dndetails[$attr])) {
 								echo '<td>&nbsp;</td>';
-								continue;
+								continue 2;
 							}
 
 							# Special case for DNs
@@ -384,7 +384,7 @@ class QueryRender extends PageRender {
 									: htmlspecialchars($dndetails['dn']);
 
 								printf('<td><a href="cmd.php?%s">%s</a></td>',htmlspecialchars($href),$dn_display);
-								continue;
+								continue 2;
 							}
 
 							# Set our object with our values
