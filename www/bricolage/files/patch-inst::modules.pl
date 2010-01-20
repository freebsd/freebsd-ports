--- inst/modules.pl.orig	2010-01-20 10:09:51.409328323 +0900
+++ inst/modules.pl	2010-01-20 10:10:27.015274883 +0900
@@ -101,7 +101,7 @@
     { 
         local $^W = 0; # ignore warnings from modules
         my $result = eval "require $name;";
-        return soft_fail("not found.") if $@;
+        return soft_fail("not found ($@).") if $@;
         print "found.\n";
     }
 
@@ -109,7 +109,7 @@
 	print "Checking that $name version is >= $req_version... ";
         local $^W = 0;
 	eval { $name->VERSION($req_version) };
-	return soft_fail("not ok.") if $@;
+	return soft_fail("not ok ($@).") if $@;
 	print "ok.\n";
     }
 
