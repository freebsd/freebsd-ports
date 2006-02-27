--- Makefile.PL.orig	Mon Feb 27 15:53:11 2006
+++ Makefile.PL	Mon Feb 27 15:56:50 2006
@@ -537,14 +537,14 @@ END
 	# Guess a default value for {install} based on whether
 	# prerequisites were found.
 	#
-	$info->{install} = $opt_yes || not $info->{missing};
+	$info->{install} = 1; #$opt_yes || not $info->{missing};
 
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
@@ -573,8 +573,8 @@ END
 		die;
 	    }
 	
-	    $info->{install} =
-	      ask(0, $msg, not $missing);
+	    $info->{install} = 1;
+	    #  ask(0, $msg, not $missing);
 	}
     }
 }
@@ -778,8 +778,8 @@ END
     }
 
     # Remove existing non-working 'uninstall' target.
-    $inherited =~ s!^uninstall\s:.*$!!m
-      or die "no uninstall target in: $inherited";
+    $inherited =~ s!^uninstall\s::?.*?\n\t+.*$!!m;
+    $inherited =~ s!^uninstall\s:.*$!!m;
 
     # For each *_install create a corresponding _uninstall.
     my $targets = ::targets($inherited);
