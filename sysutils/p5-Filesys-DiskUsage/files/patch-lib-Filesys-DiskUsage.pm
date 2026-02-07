--- lib/Filesys/DiskUsage.pm.orig	Wed Jan 19 13:51:52 2005
+++ lib/Filesys/DiskUsage.pm	Wed Sep 21 15:02:35 2005
@@ -55,7 +55,7 @@
   # get a hash
   %sizes = du( { 'make-hash' => 1 }, @files_and_directories );
 
-=head1 FUNCTIONS
+=head1 DESCRIPTION
 
 =head2 du
 
@@ -69,7 +69,7 @@
 
   $total = du(qw/file1 directory1/);
 
-=head3 OPTIONS
+=head2 OPTIONS
 
 =over 6
 
