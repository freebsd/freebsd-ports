--- Makefile.PL.orig	Sat Jun 25 06:02:32 2005
+++ Makefile.PL	Sun Apr 23 11:54:39 2006
@@ -20,6 +20,7 @@
       PL_FILES       => { 'makepm.PL' => 'config.pm' },
       PM             => { 'Rsync.pm'  => '$(INST_LIB)/File/Rsync.pm',
      			  'config.pm' => '$(INST_ARCHLIB)/File/Rsync/Config.pm' },
+      MAN3PODS       => { 'Rsync.pm'  => '$(INST_MAN3DIR)/File::Rsync.$(MAN3EXT)' },
       dist           => { COMPRESS => 'gzip', SUFFIX => 'gz' },
       realclean      => { FILES => 'config.pm' },
 );
