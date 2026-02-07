--- lib/login_tk.pl.orig	2008-03-12 03:03:39.000000000 +0100
+++ lib/login_tk.pl	2008-03-12 02:57:41.000000000 +0100
@@ -281,7 +281,7 @@
 	     -font=>$GUI{fonts}->{login},
 	     -state=>"disabled",
 	     -command=>sub{
-	       $GUI{Login}->{Connect}->configure(state=>"disabled");
+	       $GUI{Login}->{Connect}->configure(-state=>"disabled");
 
 	       $activeProfile = $GUI{Login}->{vars}->{profile};
 	       &jarlSettings_SetConfig();
