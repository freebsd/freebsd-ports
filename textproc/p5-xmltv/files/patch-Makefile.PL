--- Makefile.PL.orig	Tue Jul 20 22:32:16 2004
+++ Makefile.PL	Tue Jul 20 22:34:25 2004
@@ -456,14 +456,14 @@
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
-    if (not ask('Do you want to proceed with this configuration?', 1)) {
+    if (1 or not ask('Do you want to proceed with this configuration?', 1)) {
 	# Need to set {install} for each component by prompting.
 	foreach my $info (@opt_components) {
 	    my $missing = $info->{missing};
@@ -492,8 +492,8 @@
 		die;
 	    }
 	
-	    $info->{install} =
-	      ask($msg, not $missing);
+	    $info->{install} = 1;
+	    #  ask($msg, not $missing);
 	}
     }
 }
