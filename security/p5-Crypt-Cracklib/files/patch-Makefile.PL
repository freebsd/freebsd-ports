--- Makefile.PL	Fri Nov 27 19:50:29 1998
+++ Makefile.PL.new	Fri Jan 26 21:36:22 2001
@@ -4,6 +4,7 @@
 use ExtUtils::MakeMaker;
 use Config qw(%Config);
 
+if (0 ne 0) {
 sub MY::libscan {
 	my ($self,$path) = @_;
 
@@ -16,8 +17,10 @@
 }
 
 print "\nEnter the directory where crack.h/packer.h is located\n";
+}
 my $include = '/usr/local/include';
 my $incfile = '-Dpacker=1';
+if (0 ne 0) {
 print "[$include] ";
 
 while(<>) {
@@ -38,7 +41,9 @@
 }
 
 print "\nEnter the directory where libcrack.(so|a) is located\n";
+}
 my $lib = '/usr/local/lib';
+if (0 ne 0) {
 print "[$lib] ";
 
 while(<>) {
@@ -50,13 +55,14 @@
 		last if -f "$lib/libcrack.so" or -f "$lib/libcrack.a";
 	}
 }
+}
 
 WriteMakefile(
 	'NAME'		=> 'Crypt::Cracklib',
 	'VERSION_FROM'	=> 'Cracklib.pm',
-	'LIBS'		=> ["-L$lib -lcrack"],
+	'LIBS'		=> ["-LFBSDLIB -lcrack"],
 	'DEFINE'	=> $incfile,
-	'INC'		=> "-I$include",
+	'INC'		=> "-IINCLUDE",
 	'dist'		=> {	COMPRESS => 'gzip -9f',
 				SUFFIX   => 'gz',
 				DIST_DEFAULT => 'tardist',
