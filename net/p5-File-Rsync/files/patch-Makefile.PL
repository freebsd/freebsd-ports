--- Makefile.PL.orig	Tue Jun 26 01:36:15 2001
+++ Makefile.PL	Fri May 16 17:55:25 2003
@@ -16,9 +16,13 @@
       DISTNAME       => $DISTNAME,
       AUTHOR         => $AUTHOR,
       ABSTRACT       => $ABSTRACT,
-      PL_FILES       => { 'makepm.PL' => 'Config.pm' },
+      PL_FILES       => { 'makepm.PL ${LOCALBASE}' => 'Config.pm' },
       PM             => { 'Rsync.pm'  => '$(INST_LIB)/File/Rsync.pm',
      			  'Config.pm' => '$(INST_ARCHLIB)/File/Rsync/Config.pm' },
+      MAN3PODS => {
+	'$(INST_LIB)/File/Rsync.pm' => '$(INST_MAN3DIR)/File::Rsync.$(MAN3EXT)',
+	'$(INST_ARCHLIB)/File/Rsync/Config.pm' => '$(INST_MAN3DIR)/File::Rsync::Config.$(MAN3EXT)',
+      },
       dist           => { COMPRESS => 'gzip', SUFFIX => 'gz' },
       realclean      => { FILES => 'Config.pm' },
 );
