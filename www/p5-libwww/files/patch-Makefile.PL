$FreeBSD$

--- Makefile.PL.orig	Fri May 31 14:51:03 2002
+++ Makefile.PL	Sun Aug  4 16:02:00 2002
@@ -57,7 +57,7 @@
 
 EOT
 
-        if (prompt("Do you want to enable these tests?", "y") =~ /^y/i) {
+        if (1) {
 	    open(ENABLED, ">t/live/ENABLED") || die "Can't enable: $!";
 	    close(ENABLED);
 
@@ -95,7 +95,7 @@
 EOT
     my @tmp;
     for (@programs_to_install) {
-	if (prompt("Do you want to install $_?", "y") =~ /^y/) {
+	if (1) {
 	    push(@tmp, $_);
 	}
     }
@@ -125,7 +125,7 @@
 		}
 		close(PROG);
 	    }
-	    if (prompt("Do you want to install the $alias alias?", $default) =~ /^y/) {
+	    if (1) {
 		push(@tmp, $alias);
 	    }
 	}
