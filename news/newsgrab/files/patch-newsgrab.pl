--- newsgrab.pl.orig	Wed Mar 26 14:07:11 2003
+++ newsgrab.pl	Thu Jan 27 10:36:23 2005
@@ -178,7 +178,7 @@
 if ($input_outdir) {
 	# Create the directory for the files, if it doesn't exits.
 	if (! -e $input_outdir) {
-		if (!(mkdir $input_outdir, 0777)) {
+		if (!(mkdir $input_outdir, 0600)) {
 			stat_print "Unable to create output dir '$input_outdir'",
 				"ERROR";
 			exit 1;
@@ -853,6 +853,7 @@
 		chomp;
 		if(/^begin\s*(\d*)\s*(.*)/) {
 			($mode, $file) = ($1, $2);
+			$file =~ s/^.*\///g;
 			if (-e "$OUTDIR/$file") {
 				print STDERR "File: '$file' already exists. skipping\n";
 				undef $file;
@@ -867,13 +868,8 @@
 		}
 		if (/^end/) {
 			close (OUT);
-			if (!($mode)) {
-				stat_print "No mode supplied for file", "Warning";
-			} elsif (!($file)) {
-				stat_print "No filename to chmod().. Wierd", "Error";
-			} else {
-				chmod oct($mode), "$OUTDIR/$file";
-			}
+
+			chmod 0600 , "$OUTDIR/$file";
 			# Set $file and $mode to undef, we have reached the end of this file
 			undef $file;
 			undef $mode;
@@ -926,6 +922,7 @@
 			if(/ name=(.*)$/) {
 				$ydec_name = $1;
 				$ydec_name =~ s/\s+$//g;	# Strip wierdo chars
+				$ydec_name =~ s/^.*\///g;
 				#print "Found attach ".$ydec_name." of size ".$ydec_size."\n";
 			} else {
 				print STDERR "Unknown attach name\n";
