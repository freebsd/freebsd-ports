--- CCCheck/CCCheck.pm.orig	Fri Apr 19 18:59:51 2002
+++ CCCheck/CCCheck.pm	Fri Apr 19 19:02:33 2002
@@ -834,7 +834,7 @@
 	my $iin=substr($card_number, 0, 6);
 
 	# If we have an exact match, look up the stuff and return it
-	if ($prefixes->{$iin} ne "") {
+	if ($prefixes->{$iin} && $prefixes->{$iin} ne "") {
 		return $iin;
 	} else {
 		# We'll look for ranges. First of all, try the wide and narrow
