--- inc/Module/AutoInstall.pm.orig	2012-04-26 12:38:21.028164683 -0400
+++ inc/Module/AutoInstall.pm	2012-04-26 12:38:39.733163954 -0400
@@ -138,7 +138,7 @@
     # check entirely since we don't want to have to load (and configure)
     # an old CPAN just for a cosmetic message
 
-    $UnderCPAN = _check_lock(1) unless $SkipInstall || $InstallDepsTarget;
+#    $UnderCPAN = _check_lock(1) unless $SkipInstall || $InstallDepsTarget;
 
     while ( my ( $feature, $modules ) = splice( @args, 0, 2 ) ) {
         my ( @required, @tests, @skiptests );
