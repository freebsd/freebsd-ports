--- Portscout/DataSrc/Ports.pm.orig	2011-04-09 17:19:03 UTC
+++ Portscout/DataSrc/Ports.pm
@@ -201,7 +201,7 @@ sub BuildDB
 
 	my $lastbuild = getstat('buildtime', TYPE_INT);
 
-	print "Looking for updated ports...\n\n"
+	print "Incremental build: Looking for updated ports...\n\n"
 		if ($incremental);
 
 	$got_ports = 0;
@@ -243,12 +243,15 @@ sub BuildDB
 			my (@fields, $maintainer, $port);
 
 			@fields = split /\|/;
-			$maintainer = $fields[5];
+			$maintainer = lc($fields[5]);
 			$port = $fields[1];
 			$port =~ s/^(?:.*\/)?([^\/]+)\/([^\/]+)$/$1\/$2/;
 
-			$portsmaintok{$port} = $maintainer
-				if ($maintainers{$maintainer});
+			if ($maintainers{$maintainer}) {
+				$portsmaintok{$port} = $maintainer;
+				print "Maintainer match: $maintainer $port \n"
+					unless ($settings{quiet});
+			}
 		}
 
 		close $if;
@@ -264,7 +267,7 @@ sub BuildDB
 
 		opendir my $catdir, $settings{ports_dir}."/$cat";
 
-		print "Scanning $cat...\n"
+		print "Scanning $cat ...\n"
 			unless ($settings{quiet});
 
 		while (my $name = readdir $catdir) {
@@ -276,9 +279,9 @@ sub BuildDB
 			# port directory's mtime; skip if not updated.
 			if ($incremental) {
 				my ($updated);
-
 				opendir my $portdir, $settings{ports_dir}."/$cat/$name";
-
+				print "Scanning $cat/$name ... "
+					unless ($settings{quiet});
 				while (my $subfile = readdir $portdir) {
 					my ($subfile_path, $fi);
 
@@ -289,12 +292,18 @@ sub BuildDB
 						or die "Couldn't stat $subfile_path: $!";
 
 					if ($fi->mtime > $lastbuild) {
+						print "$subfile (mtime: $fi->mtime) modified updated since last build: $lastbuild \n"
+							if ($settings{debug});
 						$updated = 1;
 						last;
 					}
 				}
 
-				next if (!$updated);
+				if (!$updated) {
+					print "Not modified since last build: $lastbuild \n"
+						if ($settings{debug});
+					next;
+				}
 			}
 
 			# Check this port is wanted by user
@@ -307,7 +316,8 @@ sub BuildDB
 					&& $settings{indexfile_enable}) {
 				next if (!$portsmaintok{"$cat/$name"});
 			}
-
+			print "Matched: $cat/$name\n"
+				unless ($settings{quiet});
 			push @ports, "$cat/$name";
 		}
 	}
