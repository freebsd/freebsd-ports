--- lib/File/RsyncP/FileIO.pm.orig	Thu Jul 24 04:33:37 2003
+++ lib/File/RsyncP/FileIO.pm	Mon Jan 12 10:57:29 2004
@@ -44,7 +44,7 @@
 use File::Find;
 use Data::Dumper;
 
-our $VERSION = '0.44';
+use vars qw($VERSION); $VERSION = '0.44';
 
 use constant S_IFMT       => 0170000;	# type of file
 use constant S_IFDIR      => 0040000; 	# directory
@@ -664,7 +664,7 @@
 
     foreach my $str ( @logStr ) {
         next if ( $str eq "" );
-        $fio->{logHandler}($str);
+        $fio->{logHandler}->($str);
     }
 }
 
