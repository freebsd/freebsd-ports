--- lib/quote.tcl.orig	Mon Jul 26 20:23:33 2004
+++ lib/quote.tcl	Wed May 25 00:04:18 2005
@@ -23,7 +23,7 @@
 	return;
     } else {
 	if {$quote(symlink)} {
-	    if [catch {file link -symbolic $mhProfile(path)/$folder/$msg $quote(filename)} err] {
+	    if [catch {exec ln -s $mhProfile(path)/$folder/$msg $quote(filename)} err] {
 		Exmh_Debug "Quote_MakeFile: $err"
 	    }
 	} else {
