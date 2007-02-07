--- inc/libmisc.pl.orig	Mon Feb  5 17:51:32 2007
+++ inc/libmisc.pl	Mon Feb  5 17:58:33 2007
@@ -24,8 +24,8 @@
 #===================================================================
 sub ReadConf {
 
-	if (-e "$main::p/nedi.conf"){
-		open  ("CONF", "$main::p/nedi.conf");
+	if (-e "/usr/local/etc/nedi.conf"){
+		open  ("CONF", "/usr/local/etc/nedi.conf");
 	}elsif (-e "/etc/nedi.conf"){
 		open  ("CONF", "/etc/nedi.conf");
 	}else{
@@ -279,8 +279,8 @@
 		$doip{"testing"} = $main::opt{t};
 		print "$main::opt{t} added for testing\n";
 		$s++;
-	}elsif (-e "$main::p/$seedlist"){
-		open  (LIST, "$main::p/$seedlist");
+	}elsif (-e "$seedlist"){
+		open  (LIST, "$seedlist");
 		my @list = <LIST>;
 		close(LIST);
 		chomp @list;
