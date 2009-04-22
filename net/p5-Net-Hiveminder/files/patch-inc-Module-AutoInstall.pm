--- inc/Module/AutoInstall.pm.orig	2009-04-20 15:31:17.000000000 +0800
+++ inc/Module/AutoInstall.pm	2009-04-22 16:08:41.000000000 +0800
@@ -115,7 +115,7 @@
         )[0]
     );
 
-    $UnderCPAN = _check_lock(1);    # check for $UnderCPAN
+    #$UnderCPAN = _check_lock(1);    # check for $UnderCPAN
 
     while ( my ( $feature, $modules ) = splice( @args, 0, 2 ) ) {
         my ( @required, @tests, @skiptests );
