--- FileList/FileList.pm.orig	Mon Jan 12 10:52:48 2004
+++ FileList/FileList.pm	Mon Jan 12 10:53:50 2004
@@ -39,14 +39,13 @@
 
 package File::RsyncP::FileList;
 
-use 5.006;
 use strict;
-use warnings;
 
 require Exporter;
 require DynaLoader;
 
-our @ISA = qw(Exporter AutoLoader DynaLoader);
+use vars qw(@ISA %EXPORT_TAGS @EXPORT_OK @EXPORT $VERSION);
+@ISA = qw(Exporter AutoLoader DynaLoader);
 
 # Items to export into callers namespace by default. Note: do not export
 # names by default without a very good reason. Use EXPORT_OK instead.
@@ -55,16 +54,16 @@
 # This allows declaration	use File::RsyncP::FileList ':all';
 # If you do not need this, moving things directly into @EXPORT or @EXPORT_OK
 # will save memory.
-our %EXPORT_TAGS = ( 'all' => [ qw(
+%EXPORT_TAGS = ( 'all' => [ qw(
 	
 ) ] );
 
-our @EXPORT_OK = ( @{ $EXPORT_TAGS{'all'} } );
+@EXPORT_OK = ( @{ $EXPORT_TAGS{'all'} } );
 
-our @EXPORT = qw(
+@EXPORT = qw(
 	
 );
-our $VERSION = '0.44';
+$VERSION = '0.44';
 
 bootstrap File::RsyncP::FileList $VERSION;
 
