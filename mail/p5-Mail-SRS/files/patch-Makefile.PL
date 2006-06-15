--- Makefile.PL.orig	Wed Jun 23 15:53:43 2004
+++ Makefile.PL	Thu Jun  1 15:35:38 2006
@@ -1,19 +1,9 @@
-use 5.006;
 use ExtUtils::MakeMaker;
 
 # Thanks to YAML
 my @programs = ();
-for (split "\n", <<'QUERIES') {
-srs|y|SRS command line interface
-srsd|y|SRS address translation daemon
-srsc|y|SRS daemon commandline client
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
