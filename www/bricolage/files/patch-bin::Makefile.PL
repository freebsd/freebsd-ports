--- bin/Makefile.PL.orig	Mon May 24 00:10:06 2004
+++ bin/Makefile.PL	Mon May 24 00:10:24 2004
@@ -32,16 +32,6 @@
 
 # Write out the Makefile
 WriteMakefile(NAME           => 'bric_bin',
-	      EXE_FILES      => \@EXE,
-	      ( exists $CONFIG->{MODULE_DIR} ? 
-		( INSTALLSITELIB => $CONFIG->{MODULE_DIR} ) :
-		()),
-	      ( exists $CONFIG->{BIN_DIR} ? 
-		( INSTALLSCRIPT => $CONFIG->{BIN_DIR},
-                  INSTALLSITEBIN => $CONFIG->{BIN_DIR} ) :
-		()),
-	      ( exists $CONFIG->{MAN_DIR} ? 
-		( INSTALLMAN1DIR => "$CONFIG->{MAN_DIR}/man1",
-                  INSTALLSITEMAN1DIR => "$CONFIG->{MAN_DIR}/man1") :
-		()));
+              EXE_FILES      => \@EXE
+             );
 
