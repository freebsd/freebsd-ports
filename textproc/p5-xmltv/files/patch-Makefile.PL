--- Makefile.PL.orig	2014-05-09 04:07:13 UTC
+++ Makefile.PL
@@ -1031,14 +1031,14 @@ END
         # Guess a default value for {install} based on whether
         # prerequisites were found.
         #
-        $info->{install} = (not $info->{exclude}) && ($opt_yes || not $info->{missing});
+        $info->{install} = 1;(not $info->{exclude}) && ($opt_yes || not $info->{missing});
 
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
@@ -1067,8 +1067,8 @@ END
                 die;
             }
 
-            $info->{install} =
-              ask(0, $msg, not $missing);
+            $info->{install} = 1;
+            #  ask(0, $msg, not $missing);
         }
     }
 }
@@ -1272,8 +1272,8 @@ END
     }
 
     # Remove existing non-working 'uninstall' target.
-    $inherited =~ s!^uninstall\s:.*$!!m
-      or die "no uninstall target in: $inherited";
+    $inherited =~ s!^uninstall\s::?.*?\n\t+.*$!!m;
+    $inherited =~ s!^uninstall\s:.*$!!m;
 
     # For each *_install create a corresponding _uninstall.
     my $targets = ::targets($inherited);
