
$FreeBSD$

--- ProcessASN.pl.orig	Tue Oct 22 00:21:49 2002
+++ ProcessASN.pl	Tue Oct 22 00:21:53 2002
@@ -4,7 +4,7 @@
 
 #ftp://ftp.arin.net/netinfo/asn.txt
 #ftp://ftp.apnic.net/pub/apnic/dbase/data/apnic.an.gz
-#ftp://ftp.ripe.net/ripe/dbase/split/ripe.db.an.gz
+#ftp://ftp.ripe.net/ripe/dbase/split/ripe.db.aut-num.gz
 
 #and put them all in another file in a dumb format so they can
 #be processed by my dumb C program.
@@ -51,28 +51,28 @@
 	}
 }
 
-if (! -f "ripe.db.an" ) { 
-	if (-f "ripe.db.an.gz") {
-		system "$gzip -d ripe.db.an.gz";
+if (! -f "ripe.db.aut-num" ) { 
+	if (-f "ripe.db.aut-num.gz") {
+		system "$gzip -d ripe.db.aut-num.gz";
 		$r=$?;
 		if ($r > 0) {
-			print "---> Retrieved ripe.db.an.gz, but could not run $gzip!\n";
+			print "---> Retrieved ripe.db.aut-num.gz, but could not run $gzip!\n";
 			print "---> Please get $gzip and try again\n";
 			exit(1);
 		}
 	} else { 
-		if ( RetrieveFile("ftp://ftp.ripe.net/ripe/dbase/split/ripe.db.an.gz","ripe.db.an.gz")) {
-			system "$gzip -d ripe.db.an.gz";
+		if ( RetrieveFile("ftp://ftp.ripe.net/ripe/dbase/split/ripe.db.aut-num.gz","ripe.db.aut-num.gz")) {
+			system "$gzip -d ripe.db.aut-num.gz";
 			$r=$?;
 			if ($r > 0) {
-				print "---> Retrieved ripe.db.an.gz, but could not run $gzip!\n";
+				print "---> Retrieved ripe.db.aut-num.gz, but could not run $gzip!\n";
 				print "---> Please get $gzip and try again\n";
 				exit(1);
 			}
 		} else {
-			print "---> Cannot retrieve ripe.db.an.gz\n";
+			print "---> Cannot retrieve ripe.db.aut-num.gz\n";
 			print "---> Please download it from\n";
-			print "---> ftp://ftp.ripe.net/ripe/dbase/split/ripe.db.an.gz\n";
+			print "---> ftp://ftp.ripe.net/ripe/dbase/split/ripe.db.aut-num.gz\n";
 			$MissingFile=1;
 		}
 	}
@@ -109,7 +109,7 @@
 print "Processed $c ASes from asn.txt\n";
 
 ProcessRipeDB("apnic.an");
-ProcessRipeDB("ripe.db.an");
+ProcessRipeDB("ripe.db.aut-num");
 
 $c=0;
 open OUTPUT,">asnc.txt";
@@ -124,7 +124,7 @@
   $c=0;
   open APNIC,"<$file";
   while (<APNIC>) {
-	if (/^\*an: AS(..*)/) {
+	if (/^(\*an|aut-num):\s+AS(..*)/) {
 		if ($an) {
 			if ($aa) { $ASNs{$an}=$aa; $c++; }
 			elsif ($mb) { $ASNs{$an}=$mb; $c++; }
@@ -133,25 +133,25 @@
 			
 			undef $an; undef $aa; undef $mb; undef $de;
 		}
-		$an=$1;
+		$an=$2;
 	}
-	if (/^\*aa: (..*)/) {
+	if (/^(\*aa|as-name):\s+(..*)/) {
 		if (! $aa) {
-			$aa=$1;
+			$aa=$2;
 			$aa=~ s/ /_/g;
 			if ($aa eq 'UNSPECIFIED') {
 			    $aa="AS$an"; # 'an:' is always defined here
 			}
 		}
 	} 
-	if (/^\*mb: MAINT\-(..*)/) {
+	if (/^(\*mb|mnt-by):\s+MAINT\-(..*)/) {
 		if (! $mb) {
-			$mb=$1;
+			$mb=$2;
 			$mb=~ s/ /_/g;
 		}
-	} elsif (/^\*mb: (..*)/) {
+	} elsif (/^(\*mb|mnt-by):\s+(..*)/) {
 		if (! $mb) {
-			$mb=$1;
+			$mb=$2;
 			$mb=~ s/ /_/g;
 		}
 	} 
@@ -176,20 +176,12 @@
 
   print "RetrieveFile: getting $location\n";
 
-  $wget="wget";
-  $ncftp="ncftp";
-  $curl="curl";
-  system "$wget -q $location";
-  $r=$?;
-  if ($r==0) { print "Got file with $wget.\n"; return 1; }
+  $fetch="fetch";
 
-  system "$ncftp $location";
+  system "$fetch $location";
   $r=$?;
-  if ($r==0) { print "Got file with $ncftp.\n"; return 1; }
+  if ($r==0) { print "Got file with $fetch.\n"; return 1; }
 
-  system "$curl -o $filename $location";
-  $r=$?;
-  if ($r==0) { print "Got file with $curl\n"; return 1; }
-  if ($r > 0) { print "Could not get $filename with $curl, $wget or $ncftp.\n"; }
+  if ($r > 0) { print "Could not get $filename with $fetch, $curl, $wget or $ncftp.\n"; }
   return 0;
 }
