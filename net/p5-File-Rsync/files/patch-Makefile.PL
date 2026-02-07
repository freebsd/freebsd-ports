--- Makefile.PL.orig	2015-07-21 19:39:43 UTC
+++ Makefile.PL
@@ -23,6 +23,7 @@ WriteMakefile(
                           'IPC::Run3'  => 0,
                         },
       PM             => { 'Rsync.pm'  => '$(INST_LIB)/File/Rsync.pm' },
+      MAN3PODS       => { 'Rsync.pm'  => '$(INST_MAN3DIR)/File::Rsync.$(MAN3EXT)' },
       dist           => { COMPRESS => 'gzip', SUFFIX => 'gz' },
 );
 
