--- inc/Module/AutoInstall.pm.orig	2010-04-16 23:10:16.102126300 +0900
+++ inc/Module/AutoInstall.pm	2010-04-16 23:41:43.633712156 +0900
@@ -115,7 +115,7 @@
         )[0]
     );
 
-    $UnderCPAN = _check_lock(1);    # check for $UnderCPAN
+    $UnderCPAN = _check_lock();    # check for $UnderCPAN
 
     while ( my ( $feature, $modules ) = splice( @args, 0, 2 ) ) {
         my ( @required, @tests, @skiptests );
