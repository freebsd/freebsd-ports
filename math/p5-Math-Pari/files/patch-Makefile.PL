--- Makefile.PL.orig	2009-12-25 11:08:17.581369187 +0300
+++ Makefile.PL	2009-12-25 11:10:35.244866346 +0300
@@ -119,9 +119,9 @@
 }
 
 my %opts;
+  make_pod 'libPARI.pod', '-to_pod', $paridir; # Now the docs
 unless ($common::parilib) {
   build_tests $paridir;		# Convert the test suite
-  make_pod 'libPARI.pod', '-to_pod', $paridir; # Now the docs
   make_pod 'libPARI.dumb.pod', '-to_dumb_pod', $paridir;
   # ... and paricfg.h
   %opts = build_paricfg($paridir, $common::do_configure, $pari_version);
@@ -176,7 +176,7 @@
 # the contents of the Makefile being created.
 &WriteMakefile(
 	       LIBS	     =>  $libs,
-	       INC	     => $extra_inc . ' -I $(PARI_DIR)/src/headers -I $(PARI_DIR)/src -I ./libPARI',
+	       INC	     => '-I$(PREFIX)/include/pari -I$(PARI_DIR)/src',
 	       NAME	     => 'Math::Pari',
 	       ($common::parilib ? () :
 		 (MYEXTLIB   =>  'libPARI/libPARI$(LIB_EXT)')),
