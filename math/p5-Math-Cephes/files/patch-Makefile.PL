--- Makefile.PL.orig	Wed Dec 31 00:57:31 2003
+++ Makefile.PL	Fri Jun 16 12:05:48 2006
@@ -23,8 +23,8 @@
 # fool WriteMakefile into thinking there's a libmd lib
 my $lib = 'libmd' . $Config{lib_ext};
 my $dummy = catfile $libmd, $lib;
-open(DUMMY, ">$dummy") or die "Cannot create $dummy: $!";
-close DUMMY;
+#open(DUMMY, ">$dummy") or die "Cannot create $dummy: $!";
+#close DUMMY;
 
 my %opts = (
 	    NAME => 'Math::Cephes',
