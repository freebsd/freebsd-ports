--- build/version_check.pl.orig	Sun Jan  1 19:13:20 2006
+++ build/version_check.pl	Sun Jan  1 19:13:33 2006
@@ -1,6 +1,6 @@
 # version_check.pl tool version
 use strict;
-use warnings 'FATAL';
+#use warnings 'FATAL';
 use Getopt::Long qw/GetOptions/;
 GetOptions(\my %opts, "version=s");
 my ($tool, $path) = @ARGV;
@@ -128,7 +128,7 @@
 WARN
   
     $warning =~ s/^/\# /mg;
-    open(my $fh, '>', $dummy_versions)
+    open(my $fh, ">$dummy_versions")
         or die "Cannot open $dummy_versions for writing: $!";
     print $fh $warning;
 
