--- Makefile.PL.orig	Mon Oct 25 02:33:47 2004
+++ Makefile.PL	Fri Nov 26 15:29:30 2004
@@ -466,14 +466,14 @@
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
@@ -502,8 +502,8 @@
 		die;
 	    }
 	
-	    $info->{install} =
-	      ask(0, $msg, not $missing);
+	    $info->{install} = 1;
+	    #  ask(0, $msg, not $missing);
 	}
     }
 }
