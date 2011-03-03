--- Makefile.PL.orig	2010-11-22 07:04:58.000000000 +0100
+++ Makefile.PL	2011-03-03 14:50:27.000000000 +0100
@@ -804,14 +804,14 @@
 	# Guess a default value for {install} based on whether
 	# prerequisites were found.
 	#
-	$info->{install} = (not $info->{exclude}) && ($opt_yes || not $info->{missing});
+	$info->{install} = 1;(not $info->{exclude}) && ($opt_yes || not $info->{missing});
 
 	print STDERR ($s, ' ' x (1 + $width - length $s),
 		      $info->{install} ? '[yes]' : '[no]',
 		      "\n");
     }
     print STDERR "\n";
-    if (not ask(0, 'Do you want to proceed with this configuration?', 1)) {
+    if (1 or not ask(0, 'Do you want to proceed with this configuration?', 1)) {
 	# Need to set {install} for each component by prompting.
 	foreach my $info (@opt_components) {
 	    my $missing = $info->{missing};
@@ -840,8 +840,8 @@
 		die;
 	    }
 	
-	    $info->{install} =
-	      ask(0, $msg, not $missing);
+	    $info->{install} = 1;
+	    #  ask(0, $msg, not $missing);
 	}
     }
 }
@@ -1045,8 +1045,8 @@
     }
 
     # Remove existing non-working 'uninstall' target.
-    $inherited =~ s!^uninstall\s:.*$!!m
-      or die "no uninstall target in: $inherited";
+    $inherited =~ s!^uninstall\s::?.*?\n\t+.*$!!m;
+    $inherited =~ s!^uninstall\s:.*$!!m;
 
     # For each *_install create a corresponding _uninstall.
     my $targets = ::targets($inherited);
