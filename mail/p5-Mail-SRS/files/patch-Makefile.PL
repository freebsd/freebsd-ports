--- Makefile.PL.orig	Tue Feb 24 21:35:53 2004
+++ Makefile.PL	Thu May 27 13:27:13 2004
@@ -1,18 +1,9 @@
-use 5.006;
 use ExtUtils::MakeMaker;
 
 # Thanks to YAML
 my @programs = ();
-for (split "\n", <<'QUERIES') {
-srs|y|SRS command line interface
-srsd|y|SRS address translation daemon
-QUERIES
-	my ($program, $default, $description) = split /\|/, $_;
-	if (prompt("Do you want to install '$program', the $description?", 
-			   $default) =~ /^y/) {
-		push(@programs, $program);
-	}
-}
+push(@programs, "srs");
+push(@programs, "srsd");
 
 WriteMakefile(
     'NAME'		=> 'Mail::SRS',
