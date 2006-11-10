--- Makefile.PL.orig	Wed May 31 12:39:28 2006
+++ Makefile.PL	Fri Sep 15 13:45:27 2006
@@ -91,9 +91,9 @@
 }
 
 my %opts;
+  make_pod 'libPARI.pod', '-to_pod', $paridir; # Now the docs
 unless ($common::parilib) {
   build_tests $paridir;		# Convert the test suite
-  make_pod 'libPARI.pod', '-to_pod', $paridir; # Now the docs
   make_pod 'libPARI.dumb.pod', '-to_dumb_pod', $paridir;
   %opts = build_paricfg($paridir, $common::do_configure); # ... and paricfg.h
 
@@ -139,7 +139,7 @@
 # the contents of the Makefile being created.
 &WriteMakefile(
 	       LIBS	     =>  $libs,
-	       INC	     => $extra_inc . ' -I$(PARI_DIR)/src/headers -I$(PARI_DIR)/src -I./libPARI',
+	       INC	     => '-I$(PREFIX)/include/pari -I$(PARI_DIR)/src',
 	       NAME	     => 'Math::Pari',
 	       ($common::parilib ? () :
 		 (MYEXTLIB   =>  'libPARI/libPARI$(LIB_EXT)')),
