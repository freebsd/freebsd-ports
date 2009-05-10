--- inc/Module/AutoInstall.pm-old	2009-04-24 22:01:47.000000000 +0100
+++ inc/Module/AutoInstall.pm	2009-05-03 08:15:51.000000000 +0100
@@ -115,8 +115,6 @@
         )[0]
     );
 
-    $UnderCPAN = _check_lock(1);    # check for $UnderCPAN
-
     while ( my ( $feature, $modules ) = splice( @args, 0, 2 ) ) {
         my ( @required, @tests, @skiptests );
         my $default  = 1;
@@ -186,7 +184,6 @@
             !$SkipInstall
             and (
                 $CheckOnly
-                or ($mandatory and $UnderCPAN)
                 or _prompt(
                     qq{==> Auto-install the }
                       . ( @required / 2 )
@@ -217,6 +214,8 @@
         }
     }
 
+    $UnderCPAN = _check_lock();    # check for $UnderCPAN
+
     if ( @Missing and not( $CheckOnly or $UnderCPAN ) ) {
         require Config;
         print
@@ -238,7 +237,7 @@
 # Check to see if we are currently running under CPAN.pm and/or CPANPLUS;
 # if we are, then we simply let it taking care of our dependencies
 sub _check_lock {
-    return unless @Missing or @_;
+    return unless @Missing;
 
     if ($ENV{PERL5_CPANPLUS_IS_RUNNING}) {
         print <<'END_MESSAGE';
@@ -314,7 +313,7 @@
         @modules = @newmod;
     }
 
-    if ( _has_cpanplus() and not $ENV{PERL_AUTOINSTALL_PREFER_CPAN} ) {
+    if ( _has_cpanplus() ) {
         _install_cpanplus( \@modules, \@config );
     } else {
         _install_cpan( \@modules, \@config );
@@ -707,7 +706,7 @@
       if $Config;
 
     $PostambleActions = (
-        ($missing and not $UnderCPAN)
+        $missing
         ? "\$(PERL) $0 --config=$config --installdeps=$missing"
         : "\$(NOECHO) \$(NOOP)"
     );
@@ -747,7 +746,7 @@
 sub postamble {
     $PostambleUsed = 1;
 
-    return <<"END_MAKE";
+    return << ".";
 
 config :: installdeps
 \t\$(NOECHO) \$(NOOP)
@@ -758,7 +757,7 @@
 installdeps ::
 \t$PostambleActions
 
-END_MAKE
+.
 
 }
 
@@ -766,4 +765,4 @@
 
 __END__
 
-#line 1004
+#line 1003
