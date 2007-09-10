--- scripts/perl/Makefile.PL.orig	Wed Jul 18 16:40:51 2007
+++ scripts/perl/Makefile.PL	Wed Jul 18 16:47:11 2007
@@ -43,13 +43,13 @@
 	}
 	else
 	{
-		$brohome = '/usr/local/bro';
+		$brohome = $ENV{PREFIX}/bro';
 	}
 }
 
 if( ! $broconfig )
 {
-	$broconfig = "$brohome/etc/bro.cfg";
+	$broconfig = "$ENV{PREFIX}/etc/bro.cfg";
 }
 
 
