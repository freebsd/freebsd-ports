--- perl/Spread/Spread.pm	Mon Dec  8 21:12:18 2003
+++ perl/Spread/Spread.pm	Mon Dec  8 21:15:44 2003
@@ -177,8 +177,8 @@
 
   # Connect
   my($mailbox, $private_group) = Spread::connect(
-	spread_name => '4444@host.domain.com',
-	private_name => 'mrcool',
+	{ spread_name => '4803@host.domain.com',
+	private_name => 'mrcool', }
 	);
 
   # Join and leave groups
