--- Makefile.PL.orig	Wed Apr  2 21:15:42 2003
+++ Makefile.PL	Wed Apr  2 21:16:00 2003
@@ -57,7 +57,7 @@ support works as it should.
 
 EOT
 
-        if (prompt("Do you want to enable these tests?", "y") =~ /^y/i) {
+        if (1 || prompt("Do you want to enable these tests?", "y") =~ /^y/i) {
 	    open(ENABLED, ">t/live/ENABLED") || die "Can't enable: $!";
 	    close(ENABLED);
 
@@ -95,7 +95,7 @@ to install in $Config{sitebin}.
 EOT
     my @tmp;
     for (@programs_to_install) {
-	if (prompt("Do you want to install $_?", "y") =~ /^y/) {
+	if (1 || prompt("Do you want to install $_?", "y") =~ /^y/) {
 	    push(@tmp, $_);
 	}
     }
@@ -126,7 +126,7 @@ EOT
 	    }
 	    close(PROG);
 	}
-	if (prompt("Do you want to install the $alias alias?", $default) =~ /^y/) {
+	if (1 || prompt("Do you want to install the $alias alias?", $default) =~ /^y/) {
 	    push(@tmp, $alias);
 	}
     }
