--- inc/Module/AutoInstall.pm.orig	2009-07-09 16:51:30.000000000 +0800
+++ inc/Module/AutoInstall.pm	2009-08-15 13:40:38.000000000 +0800
@@ -125,7 +125,7 @@
     # check entirely since we don't want to have to load (and configure)
     # an old CPAN just for a cosmetic message
 
-    $UnderCPAN = _check_lock(1) unless $SkipInstall;
+    #$UnderCPAN = _check_lock(1) unless $SkipInstall;
 
     while ( my ( $feature, $modules ) = splice( @args, 0, 2 ) ) {
         my ( @required, @tests, @skiptests );
