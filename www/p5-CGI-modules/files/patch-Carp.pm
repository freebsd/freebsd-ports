--- CGI/Carp.pm.orig	Sat Apr  5 03:12:02 1997
+++ CGI/Carp.pm	Fri Apr 19 18:54:00 2002
@@ -218,7 +218,7 @@
 	my($handle) = $in=~/[':]/ ? $in : "$package\:\:$in"; 
 	$no = fileno($handle);
     }
-    die "Invalid filehandle $in\n" unless $no;
+    CORE::die "Invalid filehandle $in\n" unless $no;
     
     open(SAVEERR, ">&STDERR");
     open(STDERR, ">&$no") or 
