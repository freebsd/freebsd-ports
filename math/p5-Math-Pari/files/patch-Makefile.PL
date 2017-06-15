--- Makefile.PL.orig	2016-05-07 03:14:29 UTC
+++ Makefile.PL
@@ -142,9 +142,9 @@ if ($os eq "solaris") {
 }
 
 my %opts;
+  make_pod 'libPARI.pod', '-to_pod', $paridir; # Now the docs
 unless ($common::parilib) {
   build_tests $paridir;		# Convert the test suite
-  make_pod 'libPARI.pod', '-to_pod', $paridir; # Now the docs
   make_pod 'libPARI.dumb.pod', '-to_dumb_pod', $paridir;
   # ... and paricfg.h
   %opts = build_paricfg($paridir, $common::do_configure, $pari_version);
@@ -199,7 +199,7 @@ my $extra_inc = extra_includes($paridir)
 # the contents of the Makefile being created.
 &WriteMakefile(
 	       LIBS	     =>  $libs,
-	       INC	     => $extra_inc . ' -I $(PARI_DIR)/src/headers -I $(PARI_DIR)/src -I ./libPARI',
+	       INC	     => '-I$(PARI_DIR)/src',
 	       NAME	     => 'Math::Pari',
 	       ($common::parilib ? () :
 		 (MYEXTLIB   =>  'libPARI/libPARI$(LIB_EXT)')),
