--- Makefile.PL.orig	Wed Oct 22 11:08:40 2003
+++ Makefile.PL	Wed Oct 29 14:52:36 2003
@@ -208,14 +208,6 @@
 
   return %programs if grep {/^(DIFF|GREP|TZIP|GZIP|BZIP2?)=/} @args;
 
-  print<<EOF;
-You must now specify the location of external programs for decompressing
-compressed folders. You must specify the full path--otherwise you may
-accidentally execute a trojan version of the decompression program.  You can
-enter "none" to disable support for decompressing files of a given type.
-
-EOF
-
   my @path = split /$Config{path_sep}/, $ENV{PATH};
 
   foreach my $program (sort keys %programs)
@@ -227,8 +219,7 @@
 
     $full_path = 'none' if !defined $full_path || $full_path eq '';
 
-    my $choice = ExtUtils::MakeMaker::prompt(
-      "Where can I find your \"$program\" executable?" => $full_path);
+    my $choice = $full_path;
 
     $programs{$program} = undef, next if $choice eq 'none';
 
