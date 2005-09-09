
$FreeBSD$

--- html/navigator.php.orig
+++ html/navigator.php
@@ -18,7 +18,7 @@
 	 * Copy the doc directory into HTML dir
 	 */
 
-	// print "<a href='$DOCURL/NfSen.html' target='_blank' >Docu</a>\n";
+	print "<a href='$DOCURL/NfSen.html' target='_blank' >Docu</a>\n";
 
 	print "<a href='$self?bookmark=" . $_SESSION['bookmark'] . "'>Bookmark URL</a>\n";
 	print "Selected Profile:&nbsp;\n";
