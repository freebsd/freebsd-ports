--- yazwrap/Makefile.PL.orig	Tue May  6 17:59:59 2003
+++ yazwrap/Makefile.PL	Fri Sep 19 10:57:34 2003
@@ -1,8 +1,15 @@
+my $yazinc = `yaz-config --cflags`;
+my $yazlibs = `yaz-config --libs`;
+if (!$yazinc || !$yazlibs) {
+    die "ERROR: Unable to call script 'yaz-config': is YAZ installed?";
+}
+
 use ExtUtils::MakeMaker;
-$Verbose = 1;
 
 WriteMakefile(
     'NAME'	=> 'Net::Z3950::yazwrap',
+    'LIBS'      => [ $yazlibs ],
+    'INC'       => $yazinc,
     'SKIP'	=> [qw(all static dynamic test)],
     'clean'	=> {'FILES' => 'libyazwrap$(LIB_EXT)'},
 	      'OPTIMIZE' => '-g',	### temporary
