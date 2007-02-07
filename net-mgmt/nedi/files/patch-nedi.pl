--- nedi.pl.orig	Mon Feb  5 17:07:23 2007
+++ nedi.pl	Mon Feb  5 17:14:13 2007
@@ -53,7 +53,7 @@
 if($opt{u}){
 	$misc::seedlist = "$opt{u}";
 }else{
-	$misc::seedlist = "seedlist";
+	$misc::seedlist = "/usr/local/etc/nedi.seedlist";
 }
 # Disable buffering so we can see what's going on right away.
 select(STDOUT); $| = 1;
