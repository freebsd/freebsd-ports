--- Makefile.PL.orig	Sun May 20 10:30:46 2001
+++ Makefile.PL	Sun May 20 10:33:25 2001
@@ -16,7 +16,7 @@
       DISTNAME       => $DISTNAME,
       AUTHOR         => $AUTHOR,
       ABSTRACT       => $ABSTRACT,
-      PL_FILES       => { 'makepm.PL' => 'Config.pm' },
+      PL_FILES       => { 'makepm.PL ${LOCALBASE}' => 'Config.pm' },
       PM             => { 'Rsync.pm'  => '$(INST_LIB)/File/Rsync.pm',
      			  'Config.pm' => '$(INST_ARCHLIB)/File/Rsync/Config.pm' },
       dist           => { COMPRESS => 'gzip', SUFFIX => 'gz' },
