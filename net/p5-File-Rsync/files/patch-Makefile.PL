--- Makefile.PL.orig	Sat Jun 25 06:02:32 2005
+++ Makefile.PL	Sun Apr 23 11:54:39 2006
@@ -18,6 +18,7 @@
       ABSTRACT       => $ABSTRACT,
       PREREQ_PM      => { 'Scalar::Util' => 0 },
       PM             => { 'Rsync.pm'  => '$(INST_LIB)/File/Rsync.pm' },
+      MAN3PODS       => { 'Rsync.pm'  => '$(INST_MAN3DIR)/File::Rsync.$(MAN3EXT)' },
       dist           => { COMPRESS => 'gzip', SUFFIX => 'gz' },
 );
 
