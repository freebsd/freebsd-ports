--- lib/Makefile.PL.orig	Mon May 24 00:10:13 2004
+++ lib/Makefile.PL	Mon May 24 00:11:37 2004
@@ -36,11 +36,5 @@
 
 # Write out the Makefile
 WriteMakefile(NAME           => 'Bric',
-              PM             => \%PM,
-              ( exists $CONFIG->{MODULE_DIR} ?
-                ( INSTALLSITELIB => $CONFIG->{MODULE_DIR} ) :
-                ()),
-              ( exists $CONFIG->{MAN_DIR} ?
-                ( INSTALLMAN3DIR => "$CONFIG->{MAN_DIR}/man3",
-                  INSTALLSITEMAN3DIR => "$CONFIG->{MAN_DIR}/man3") :
-                ()));
+              PM             => \%PM
+             );
